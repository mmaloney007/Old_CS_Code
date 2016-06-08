
#include "DL.h"

/* functions to be placed in object file */
double six(long, double, long, double, long, double);

/* number of functions to place in object file */
int function_count = 1;

int PLT_length = 1;

PLTentry localPLT[] = {
  { "six", "", (void (*)(void)) six, PLT_INSYMBOL}
};

/* code to be placed in object file should be placed following this comment */

double six(long a, double b, long c, double d, long e, double f)
{
  return a + b + c + d + e + f;
}

/* code to be placed in object file should be placed before this comment */

void TERMINATOR(void) { return; }

/* functions need to be listed in order; TERMINATOR must be last */
void (*(func_list[]))(void) = {
(void (*)(void)) six,
TERMINATOR
};

