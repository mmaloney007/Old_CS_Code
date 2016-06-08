/*
 * defs.h - global definitions for cs611 assembler
 *
 */

#include <stdio.h>

#define MAX_ADDRESS 16000   /* size of assembler "memory" */

typedef int STATUS;
#define FAIL 0
#define SUCCEED 1

/* typedefs for parser/scanner */

typedef enum {REGoperand, ICONSToperand, SYMoperand, NULLoperand} OPERAND_TYPE;

typedef struct {
    OPERAND_TYPE operand;
    union {
        char *sym;
        int   val;
    } u;
} OPERAND;

typedef struct {
    char  * opcode;
    OPERAND op1;
    OPERAND op2;
    OPERAND op3;
    OPERAND op4;
} INSTRUCTION;

/* error message routines (error.c) */
extern void fatal(char *fmt, ...);
extern void bug(char *fmt, ...);
extern void error(char *fmt, ...);
extern void parseError(char *fmt, ...);

/* guts of the assembler (assemble.c) */
extern void initializeAssemble(void);
extern void assemble(char *, INSTRUCTION);  /* label and/or instruction */
extern void* returnPointerToObjectCode(void);
extern int returnLengthOfObjectCode(void);

/* symbol table (symtab.c) */
extern void symtabInstall(char *, int);     /* symbol table routines */
extern STATUS symtabLookup(char *, int *);
extern void *symtabInitIter(void);          /* initialize iterator */
extern char *symtabNext(void *, int *);     /* iterate through symbol table */

/* implement directives */
void doExec(void);
void doDump(void);

