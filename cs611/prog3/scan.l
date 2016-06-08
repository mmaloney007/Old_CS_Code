%{
/*
 * lex input for scanner for cs611 assembler
 *
 */

#include        <stdlib.h>
#include        <ctype.h>
#include        <string.h>
#include        "defs.h"
#include        "y.tab.h"

/* local prototypes */
static char * stashStr(void);
static int convertIntConst(void);
static int convertRegName(void);

/* following supports the stand-alone scanner program: lexdbg */
#ifdef DEBUG
#        define token(x)        (DisplayToken(# x),  x)
        YYSTYPE yylval;
        int DisplayToken (char *);

#else

#        define token(x) x

#endif


/* current line number in input file */
static int srclineno=1;

%}

letter                    [a-zA-Z]

digit                     [0-9]

whitespace                [ \t]

newline                   [\n]

id                        ({letter}({letter}|{digit})*)

int_const                 (({digit}+)|(-({digit}+)))

comment                   [#](.)*[\n]

string                    ["](.)*["]

other                     .

%%

"!exec"                   return token(EXEC);

"!dump"                   return token(DUMP);

"("                       return token(LPAREN);

")"                       return token(RPAREN);

":"                       return token(COLON);

","                       return token(COMMA);

"$sp"                     {
                          yylval.y_int = 30;
                          return token(REG); 
                          }

"$"{int_const}            {
                          yylval.y_int = convertRegName(); 
                          return token(REG); 
                          }

{id}                      { 
                          yylval.y_str = stashStr(); 
                          return token(ID);
                          }

{int_const}               {
                          yylval.y_int = convertIntConst();
                          return token(INT_CONST);
                          }


{whitespace}+             ;

{newline}                 {
                          srclineno++;
                          return token(EOL);
                          }

{comment}                 {
                          srclineno++;
                          return token(EOL);
                          }

{string}                  {
                          yylval.y_str = stashStr(); 
                          /* discard quote on either end */
                          /* sleezy: will be hard to free space.... */
                          yylval.y_str++;
                          yylval.y_str[strlen(yylval.y_str)-1] = 0;
                          return token(STR);
                          }

{other}                   return token(ERR);

%%

/* stashStr

   copy token string to safe place; return addr of safe place
*/
static
char * stashStr(void)
{
        char *ret;
        int i;
        int len;

        len = strlen(yytext);
        ret = (char *) malloc(len+1);
        if (!ret)
        {
            fatal("out of memory in stashStr");
        }
        for (i = 0; i < len; i++)
            ret[i] = yytext[i];
        ret[i] = 0;
        return ret;
}

/* convertIntConst

   convert integer constant token from string to integer
*/
static
int convertIntConst(void)
{
        int ret;

        sscanf(yytext,"%d",&ret);
        return ret;
}

/* convertRegName

   convert integer register name token from string to integer
*/
static
int convertRegName(void)
{
        int ret;

        /* skip the $ */
        sscanf(yytext+1,"%d",&ret);
        return ret;
}

/* YYlineno

   return current line number in input file

   replaces direct access to yylineno, which is not supported by both
   lex/yacc and flex/bison.

*/
int YYlineno(void)
{
        return srclineno;
}

/* following supports the stand-alone scanner program: lexdbg */
#ifdef        DEBUG
        main()
        {
                char *p;

                while (yylex());
        }

        int DisplayToken(char *p)
        {
             printf("%-10.10s is \"%s\"\n", p, yytext);
             return 1;
        }
#endif

