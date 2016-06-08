/*
 *
 * main.c - main routine for cs611 assembler
 *
 *          Usage: as611 file.s
 *
 */

#include <stdio.h>
#include "defs.h"


/*
        main

*/
int main(int argc, char *argv[])
{
     extern FILE *yyin;
     extern FILE *yyerfp;

     if (argc != 2)
     {
         fprintf(stderr,"usage: as611 file.s\n");
         exit(1);
     }

     if (!(yyin = fopen(argv[1],"r")))
     {
         fprintf(stderr, "can't open %s\n",argv[1]);
         exit(1);
     }

     yyerfp = stderr;

     initializeAssemble();  /* initialize target code area */

     yyparse();        /* syntax driven translation! */

     return 0;
}

