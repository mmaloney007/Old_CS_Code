/*
 * symtab.c - symbol table routines for cs611 assembler
 *
 *            symbol table is implemented as a simple linked list
 *
 *            addr field is signed to allow sign to stand for
 *                outsymbol or insymbol
 */

#include <stdlib.h>
#include "defs.h"

typedef struct symtab {
        char *          id;
        int             addr;
        struct symtab * next;
              } SYMTAB_REC;

static struct symtab * symtab = 0;   /* symbol table initially empty */

/*
 *        symtabInstall
 *
 *        install (id,addr) pair into symbol table
 */
void symtabInstall(char *id, int addr)
{
        SYMTAB_REC *st=symtab;  /* begin search at beginning of linked list */

        /* see if record already exists for id */
        while (st)     /* ie while 'st' is not NULL pointer */
        {
                if (!strcmp(id,st->id))
                {
                        st->addr = addr;  /* overwrite existing record */
                        return;
                }
                st = st->next;
        }
        /* not found so insert new record */
        st = (SYMTAB_REC *) malloc(sizeof(SYMTAB_REC));
        if (!st)
        {
            fatal("out of memory in symtabInstall!");
        }
        else
        {
            st->id = id;
            st->addr = addr;
            st->next = symtab;        /* insert on front of linked list */
            symtab = st;
        }
        return;
}
                        
/*
 *        symtabLookup
 *
 *        lookups id in symtab; returns status of whether found or not;
 *        if found, addr is returned through output parameter 'addr'
 */
STATUS symtabLookup(char *id, int *addr)
{
        SYMTAB_REC *st=symtab;  /* begin search at begininng of linked list */

        while (st)     /* ie while 'st' is not NULL pointer */
        {
                if (!strcmp(id,st->id))
                {
                        *addr = st->addr;
                        return SUCCEED;
                }
                st = st->next;
        }
        return FAIL;
}

struct iterator
{
    SYMTAB_REC *next;
};

/*
 *        symtabInitIter
 *
 *        initializes an iterator to traverse symbol table
 *
 *        NOTE: symbol table should not be modified during an iterator
 *              sequence!
 */
void *symtabInitIter(void)
{
    struct iterator *ret = (struct iterator *) malloc(sizeof(struct iterator));
    if (!ret)
    {
        fatal("out of memory in symtabInitIter!");
    }
    else
    {
        ret->next = symtab;
    }
    return (void *) ret;
}

/*
 *        symtabNext
 *
 *        gets next symbol table record for an iterator sequence
 *        returns NULL when sequence is done
 */
char *symtabNext(void *inIter, int *outAddr)
{
    char *ret;
    struct iterator *iter = (struct iterator *) inIter;
    if (!iter->next)
    {
        free(iter);
        return NULL;
    }
    *outAddr = iter->next->addr;
    ret = iter->next->id;
    iter->next = iter->next->next;
    return ret;
}

