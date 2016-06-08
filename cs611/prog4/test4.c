#include <stdio.h>
#include "DL.h"

int main(int, char* []);

PLTentry localPLT[] = {
  { "main", 0, (void (*)(void)) main, PLT_INSYMBOL},
  { "six", "six.obj", DLstub, PLT_OUTSYMBOL }
};

PLTentry* PLT = localPLT;

long PLTlength = 2;

long PLTstatus = PLT_STATIC_TABLE;

int main(int argc, char* argv[])
{
  printf("%f\n",
    /* call six(1,2.0,3,4.0,5,6.0) */
    invokePLT(1,
      double (*)(long,double,long,double,long,double),
      (1,2.0,3,4.0,5,6.0)
    )
  );

  return 0;
}

