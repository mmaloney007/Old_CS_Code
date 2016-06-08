/*
 *
 * yacc input for parser for cs611 assembler
 *
 */

%{
#include <stddef.h>
#include <stdio.h>
#include "defs.h"

static OPERAND NOoperand = {NULLoperand};
static INSTRUCTION NOinstruction = {NULL};
%}

/*
 *      this types the semantic stack
 */
%union  {
        int          y_int;
        char       * y_str;
        INSTRUCTION  y_instruction;
        OPERAND      y_operand;
        }

/*
 *        terminal symbols
 */
%token <y_str> ID
%token <y_int> REG
%token <y_int> INT_CONST
%token EOL
%token COLON
%token LPAREN
%token RPAREN
%token COMMA
%token EXEC
%token DBG
%token DISS
%token DUMP
%token READOBJ
%token WRITEOBJ
%token ERR
%token <y_str> STR

/*
 *      typed non-terminal symbols
 */
%type         <y_str>         label, opcode
%type         <y_instruction> instruction
%type         <y_operand>     operand



%%

program
        : stmt stmt_list
        ;

stmt_list
        : /* null derive */

        | stmt stmt_list

        ;

stmt
        : label instruction EOL
          {
             assemble($1, $2);
          }
        | instruction EOL
          {
             assemble(NULL, $1);
          }
        | label EOL
          {
             assemble($1, NOinstruction);
          }
        | directive
          {
             /* no action: directives done in place below */
          }
        | label
          {
             assemble($1, NOinstruction); /* must do before directive is parsed! */
          }
          directive
          {
             /* no action: directives done in place below */
          }
        | EOL
          {
             /* no action */
          }
        | error EOL
          {
             /* error recovery - sync with end-of-line */
          }
        ;

label
        : ID COLON
          {
             $$ = $1;
          }
        ;

instruction
        : opcode operand COMMA operand
          {
             $$.opcode = $1;
             $$.op1 = $2;
             $$.op2 = $4;
             $$.op3 = NOoperand;
             $$.op4 = NOoperand;
          }
        | opcode operand COMMA operand COMMA operand
          {
             $$.opcode = $1;
             $$.op1 = $2;
             $$.op2 = $4;
             $$.op3 = $6;
             $$.op4 = NOoperand;
          }
        | opcode operand COMMA LPAREN operand RPAREN
          {
             $$.opcode = $1;
             $$.op1 = $2;
             $$.op2 = NOoperand;
             $$.op3 = NOoperand;
             $$.op4 = $5;
          }
        | opcode operand COMMA operand LPAREN operand RPAREN
          {
             $$.opcode = $1;
             $$.op1 = $2;
             $$.op2 = NOoperand;
             $$.op3 = $4;
             $$.op4 = $6;
          }
        ;

opcode
        : ID
          {
             $$ = $1;
          }
        ;

operand
        : REG
          {
             $$.operand = REGoperand;
             $$.u.val = $1;
          }
        | INT_CONST         /* immediate constant */
          {
             $$.operand = ICONSToperand;
             $$.u.val = $1;
          }
        | ID                 /* symbol */
          {
             $$.operand = SYMoperand;
             $$.u.sym = $1;
          }
        ;

directive
        : EXEC EOL
          {
              doExec();
          }
        | DUMP EOL
          {
              doDump();
          }
        ;



%%

FILE * yyerfp;

/* yyerror

   yacc created parser will call this when syntax error occurs
*/
yyerror(s)
        char *s;
{
        parseError(s); 

}
