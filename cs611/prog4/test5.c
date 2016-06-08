#include <stdio.h>
#include "DL.h"

int main(int, char* []);

PLTentry localPLT[] = {
  { "main", 0, (void (*)(void)) main, PLT_INSYMBOL},
  { "seven", "seven.obj", DLstub, PLT_OUTSYMBOL }
};

PLTentry* PLT = localPLT;

long PLTlength = 2;

long PLTstatus = PLT_STATIC_TABLE;

int main(int argc, char* argv[])
{
  printf("%d\n",
    /* call seven(1,2.0,3,4.0,5,6.0,7,8.0,9) */
    invokePLT(1,
      int (*)(long,double,long,double,long,double,long,double,long),
      (1,2.0,3,4.0,5,6.0,7,8.0,9)
    )
  );

  return 0;
}

