
#include "DL.h"

/* functions to be placed in object file */
int two(void);
int four(void);

/* number of functions to place in object file */
int function_count = 2;

int PLT_length = 4;

PLTentry localPLT[] = {
  { "two", "", (void (*)(void)) two, PLT_INSYMBOL},
  { "three", "three.obj", 0, PLT_OUTSYMBOL},
  { "four", "", (void (*)(void)) four, PLT_INSYMBOL},
  { "five", "three.obj", 0, PLT_OUTSYMBOL}
};

/* code to be placed in object file should be placed following this comment */

int two(void)
{
  declarePLTpointer;

  setPLT();

  /* call three() */
  return invokePLT(1, int (*)(void), ());
}

int four(void)
{
  declarePLTpointer;

  setPLT();

  /* call five() */
  return invokePLT(3, int (*)(void), ());
}

/* code to be placed in object file should be placed before this comment */

void TERMINATOR(void) { return; }

/* functions need to be listed in order; TERMINATOR must be last */
void (*(func_list[]))(void) = {
(void (*)(void)) two,
(void (*)(void)) four,
TERMINATOR
};

