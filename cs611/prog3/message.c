/*
 * message.c - display error messages for cs611 assembler
 *
 */

#include <stdio.h>
#include <stdarg.h>

extern FILE * yyerfp;

/* note: YYlineno gets advanced to next line before "assemble" is called.
 *       therefore, we subtract one before printing it in this module
 *       except for in parseError, which is only called by the parser
 */
extern int YYlineno(void);

static char buf[1024];

/*
        error

        print error message (ie user made mistake)

*/
void error(char * fmt, ...)
{
        va_list ap;
        va_start(ap, fmt);
        vsprintf(buf, fmt, ap);
        va_end(ap);
        fprintf(yyerfp,"[error] line %d:  %s\n", YYlineno()-1, buf);
}

/*
        parseError

        print error message when parse error encountered
        (like "error" except don't subtract one from YYlineno)

*/
void parseError(char * fmt, ...)
{
        va_list ap;
        va_start(ap, fmt);
        vsprintf(buf, fmt, ap);
        va_end(ap);
        fprintf(yyerfp,"[error] line %d:  %s\n", YYlineno(), buf);
}

/*
        fatal

        print fatal assembler error message

        (usually means some internal data structure overflowed)
*/
void fatal(char * fmt, ...)
{
        va_list ap;
        va_start(ap, fmt);
        vsprintf(buf, fmt, ap);
        va_end(ap);
        fprintf(yyerfp,"[internal fatal error] line %d:  %s\n",
                YYlineno()-1, buf);
        exit(1);
}

/*
        bug

        print assembler internal error message

        (shouldn't happen?!)
*/
void bug(char * fmt, ...)
{
        va_list ap;
        va_start(ap, fmt);
        vsprintf(buf, fmt, ap);
        va_end(ap);
        fprintf(yyerfp,"[internal bug] line %d:  %s\n", YYlineno()-1, buf);
        exit(1);
}

