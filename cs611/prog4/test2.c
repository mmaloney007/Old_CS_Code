#include <stdio.h>
#include "DL.h"

int main(int, char* []);

PLTentry localPLT[] = {
  { "zero", "zero.obj", DLstub, PLT_OUTSYMBOL },
  { "one", "one.obj", DLstub, PLT_OUTSYMBOL },
  { "main", 0, (void (*)(void)) main, PLT_INSYMBOL}
};

PLTentry* PLT = localPLT;

long PLTlength = 3;

long PLTstatus = PLT_STATIC_TABLE;

int main(int argc, char* argv[])
{
                 /* call zero at PLT index 0 */
  printf("%d\n", invokePLT(0, int (*)(void),()));

                 /* call one at PLT index 1 */
  printf("%d\n", invokePLT(1, int (*)(void),()));

                 /* call zero at PLT index 0 */
  printf("%d\n", invokePLT(0, int (*)(void),()));

  return 0;
}

