#include <stdio.h>
#include "DL.h"

int main(int, char* []);

PLTentry localPLT[] = {
  { "main", 0, (void (*)(void)) main, PLT_INSYMBOL},
  { "two", "two.obj", DLstub, PLT_OUTSYMBOL }
};

PLTentry* PLT = localPLT;

long PLTlength = 2;

long PLTstatus = PLT_STATIC_TABLE;

int main(int argc, char* argv[])
{
                 /* call two() */
  printf("%d\n", invokePLT(1, int (*)(void),()));

  return 0;
}

