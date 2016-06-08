/*
 * directives.c - processing of as611 directives
 *
 */

#include <stdio.h>
#include "defs.h"

/*  doExec

    Implement the !exec directive and execute the assembled code.

    Calls returnPointerToObjectCode() to get the base address of the
    assembled code. Converts it to a function pointer. And then calls it!

    I am relying on the call being implemented by the C compiler in the
    standard way. That is, Alpha register 27 ($27, procedure address)
    should be set to the address being called. Therefore register 27
    will always point to the base address of the code whenever the
    as611-assembled code is executing (assuming the as611 user does
    not explicitly manipulate register 27).
*/
void doExec(void)
{
    void *iter = symtabInitIter();
    int len = returnLengthOfObjectCode();
    int addr;
    char *sym;
    int err = 0;

    union {  /* need to convert void* to function pointer */
      void* base;
      int (*func)(void);
    } u;

    if (len <= 0)
    {
        error("no object code for !exec");
        return;
    }

    /* first check for any undefined symbols */
    while (sym = symtabNext(iter, &addr))
    {
        /* outsymbols are stored with negative addresses */
        if (addr < 0)
        {
            error("%s is undefined", sym);
            err = 1;
        }
    }

    u.base = returnPointerToObjectCode();

    /* print the value returned by the called code */
    if (!err)
        printf("!exec returns %d\n", (*u.func)());
}

/*  doDump

    Implement the !dump directive and dump the assembled code
    in hexadecimal format.

*/
void doDump(void)
{
    unsigned char *start = returnPointerToObjectCode();
    int len = returnLengthOfObjectCode();
    int cur = 0;
    int i;

    if (len <= 0)
    {
        error("no object code for !dump");
        return;
    }

    while (len)
    {
        printf("%05x  ", cur);
        for (i = 0; (i < 20) && (len); i++)
        {
            printf("%02X ", start[cur]);
            len--;
            cur++;
        }
        printf("\n");
    }
}

