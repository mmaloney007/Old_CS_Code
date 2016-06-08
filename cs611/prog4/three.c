
#include "DL.h"

/* functions to be placed in object file */
int three(void);
int five(void);

/* number of functions to place in object file */
int function_count = 2;

int PLT_length = 4;

PLTentry localPLT[] = {
  { "two", "two.obj", 0, PLT_OUTSYMBOL},
  { "three", "", (void (*)(void)) three, PLT_INSYMBOL},
  { "four", "two.obj", 0, PLT_OUTSYMBOL},
  { "five", "", (void (*)(void)) five, PLT_INSYMBOL}
};

/* code to be placed in object file should be placed following this comment */

int three(void)
{
  declarePLTpointer;

  setPLT();

  return invokePLT(2, int (*)(void), ());
}

int five(void)
{
  return 5;
}

/* code to be placed in object file should be placed before this comment */

void TERMINATOR(void) { return; }

/* functions need to be listed in order; TERMINATOR must be last */
void (*(func_list[]))(void) = {
(void (*)(void)) three,
(void (*)(void)) five,
TERMINATOR
};

