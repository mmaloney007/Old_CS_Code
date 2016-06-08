/*
 *  This file, when linked with genObjectFile.o will generate an
 *  object file containing the single function "zero" given below.
 *
 *  Note that code to be placed in an object file cannot contain
 *  references to global variable and all function calls must be
 *  made using the invokePLT macro from DL.h, supported by the
 *  declarePLTpointer and setPLT macros.
 *
 *  Also note that the correct symbol information must be placed
 *  in the localPLT variable.
 */

#include "DL.h"

/* functions to be placed in object file */
int zero(void);

/* number of functions to place in object file */
int function_count = 1;

int PLT_length = 2;

PLTentry localPLT[] = {
  { "one", "one.obj", 0, PLT_OUTSYMBOL},
  { "zero", "", (void (*)(void)) zero, PLT_INSYMBOL}
};

/* code to be placed in object file should be placed following this comment */

int zero(void)
{
  declarePLTpointer;

  setPLT();

  /* call "one" at PLT index 0 */
  return invokePLT(0, int (*)(void), ());
}

/* code to be placed in object file should be placed before this comment */

void TERMINATOR(void) { return; }

/* functions need to be listed in order; TERMINATOR must be last */
void (*(func_list[]))(void) = {
(void (*)(void)) zero,
TERMINATOR
};

