
#include "DL.h"

/* functions to be placed in object file */
int seven(long, double, long, double, long, double, long, double, long);

/* number of functions to place in object file */
int function_count = 1;

int PLT_length = 1;

PLTentry localPLT[] = {
  { "seven", "", (void (*)(void)) seven, PLT_INSYMBOL}
};

/* code to be placed in object file should be placed following this comment */

int seven(long a, double b, long c, double d, long e, double f, long g,
  double h, long i)
{
  return a + b + c + d + e + f + g + h + i;
}

/* code to be placed in object file should be placed before this comment */

void TERMINATOR(void) { return; }

/* functions need to be listed in order; TERMINATOR must be last */
void (*(func_list[]))(void) = {
(void (*)(void)) seven,
TERMINATOR
};

