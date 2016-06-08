/*
 *  DL.h: This header file contains definitions to support the simple
 *        dynamic linker for the Alpha architecture.
 */

/*
 *  This defines a PLT (procedure linking table) entry.
 */
typedef struct {
  char *procedureName;
  char *objectFileName;             /* object file containing procedure */
  void (*procedureAddress)(void);
  long status;                      /* PLT_OUTSYMBOL or PLT_INSYMBOL */
} PLTentry;

/* symbolic constants for status field of PLTentry */
#define PLT_OUTSYMBOL 0
#define PLT_INSYMBOL 1

/* Points to the base of the PLT, which might be moved. */
extern PLTentry* PLT;

/* Current length of PLT, which grows as code is linked in. */
extern long PLTlength;

/* Status of PLT: PLT_STATIC_TABLE or PLT_DYNAMIC_TABLE */
extern long PLTstatus;

/*  symbolic constants for PLTstatus:
 *    is the PLT table statically allocated or dynamically allocated?
 */
#define PLT_STATIC_TABLE 0
#define PLT_DYNAMIC_TABLE 1

/* This is the assembly language stub that calls the dynamic linker. */
extern void DLstub(void);

/*  This is the tricky part. A function that has been dynamically linked will
 *  find the PLT via a pointer that is in the quadword immediately preceding
 *  the function itself. The dynamic linker is responsible for setting
 *  up this quadword when it loads in the code for the function. This
 *  pointer will point to a global pointer that points to the (base of the)
 *  PLT itself.
 *
 *  Also there is a second quadword, immediately in front of the pointer to
 *  the PLT pointer. This quadword contains the number of PLT entries that
 *  precede the PLT entries relevant to this function. As dynamic linking
 *  occurs, PLT entries are concatenated. Each PLT index used by an object
 *  file is relative to the set of PLT entries contained in the file itself.
 *  The second quadword is added to an PLT index to get the PLT entry when
 *  doing a call through the PLT.
 *
 *  Ok, the trick is to find the two quadwords. Upon entry to a function
 *  we grab the procedure value, which is by convention in register 27,
 *  and decrement it to get the address of the longword. We then fetch
 *  the PLT address from that quadword.  We use the gcc asm facility to
 *  get access to the procedure value register ($27). We can decrement
 *  the register 27 value a second time to get the address of the second
 *  quadword.
 *
 *  The second tricky part is that the dynamic linker needs to know which
 *  PLT entry caused the linker to be invoked. The gcc asm facility is again
 *  used to PUSH the PLT entry address on top of the stack. If the dynamic
 *  linker is to be called, an assembly language function is first called
 *  that can find this PLT entry address and then call the dynamic linker,
 *  which can then be written in C. Note: by PUSH I mean that the value is
 *  put outside of the current frame, at -8($sp).
 *
 *  Note that the invokePLT macro can be used in code that was statically
 *  linked and will then refer to a PLT global.
 */
#define declarePLTpointer \
   PLTentry* PLT

#define setPLT() \
   __asm__ volatile ("stq $27, %0\n" : "=m" (PLT)); \
   PLT = (**((PLTentry ***) (void *) (((long *) (void *) PLT) - 1))) + \
           (*((((long *) (void *) PLT) - 2)))

#define invokePLT(PLTindex, calleePrototype, args) \
  ({ __asm__ volatile ("stq %0, -8($30)\n" :: "r" (PLT + PLTindex)); \
  (*((calleePrototype) (PLT[PLTindex].procedureAddress)))args; })

