//Victor Maloney CS 611 Assignment 3

#include <stdlib.h>
#include <stddef.h>
#include "defs.h"

static int opcodedecoder(char *s, int *func);
static int buffer[(MAX_ADDRESS / 4)];
static int offset = 0;

/*
 *        initializeAssemble
 *
 *        Initialize the assembler data structures.
 */
void initializeAssemble(void)
{
}

/*
 *        assemble
 *
 *        Assemble one label and/or instruction.
 */
void assemble(char *label, INSTRUCTION instr)
{
	// -------INTS NEEDED FOR THE PROGRAM -------------------

	int op=0x00000000; //keeps track of op code
	int rega=0x00000000; //does register a
	int regb=0x00000000; //does register b and sometimes ICONST
	int regc=0x00000000; //does register c and sometimes ICONST
	int regd=0x00000000; //does register d and sometimes ICONST
	int disp=0x00000000; //keeps track of displacement
	int instruct = 0x00000000; //final instructions
	int addr = 0x00000000; //works with symtable
	int func = 0x00000000; //keeps track of the function type
	int tmp = 0x00000000; //helps with symtable
	int tmp2 = 0x00000000; //helps with symtable
	int tmp3 = 0x00000000; //helps with symtable
	int tmp4 = 0x00000000; //helps with symtable
	int tmp5 = 0x00000000; //helps with symtable
	int i=0; //debugging purposes

	// -----------------CHECK LABEL IF ELSE----------------

	if(label != NULL)
	{
		if(symtabLookup(label, &addr) == SUCCEED)
		{
			if(addr < 0)
			{
			tmp3 = (tmp3 | (0x08 << 26));
			while(addr < 0)
			{
				tmp = (-1 * (addr + 1));
				tmp4 = (buffer[tmp] & tmp3);
				if(tmp4 == tmp3)
				{
					// ---Works for Memory Instructions---
					tmp5 = buffer[tmp] & 0xffff;
					addr = (-1 * tmp5);
					buffer[tmp] = buffer[tmp] & 0xffff0000;
					buffer[tmp] = (buffer[tmp] | ((offset * 4) & 0xffff));
				}
				else
				{
					// ---Works for Branch Instructions---
					tmp5 = buffer[tmp] & 0x1fffff;
					tmp4 = (offset + addr); 
					buffer[tmp] = (buffer[tmp] & 0xffe00000);
					buffer[tmp] = (buffer[tmp] | tmp4);
					addr = (-1 * tmp5);
					tmp3 = 33; //my lucky number
				}
			}
		}			
		else
		{
			error("duplicate label name");
		}
		}
		else
		{
			symtabInstall(label, offset);
		}
	}

	op = opcodedecoder(instr.opcode, &func);

	// -------------------OPERATE INSTRUCTIONS-------------------
	// -----------TWO REGISTERS, FUNCTION CODE, & REG OR LIT-----

	if(func == 1)
	{
		if(instr.op1.operand == REGoperand)
		{
			rega = instr.op1.u.val;
			if((rega < 32) && (rega >= 0))
			{
				rega = rega << 21;
			}
			else
			{
				error("illegal register number");
			}
		}
		else
		{
			error("illegal, missing or extra operand");
		}

		if(instr.op2.operand == REGoperand)
		{
			regb = instr.op2.u.val;
			if((regb < 32) && (regb >= 0))
			{
				regb = regb << 16;
			}
			else
			{
				error("illegal register number");
			}
		}
		else if(instr.op2.operand == ICONSToperand)
		{
			if((instr.op2.u.val >= 0) && (instr.op2.u.val <= 255))
			{
				regb = instr.op2.u.val;
				regb = regb << 13;
				regb = regb | (0x1 << 12);
			}
			else 
			{
				error("literal overflows 8-bit field");
			}
		}
		else
		{
			error("illegal, missing or extra operand");
		}

		if(instr.op3.operand == REGoperand)
		{
			regc = instr.op3.u.val;
			if((regc > 32) || (regc < 0))
			{
				error("illegal register number");
			}
		}
		else
		{
			error("illegal, missing or extra operand");
		}

		if(instr.op4.operand != NULLoperand)
		{
			error("illegal, missing or extra operand");
		}

	instruct = op | rega | regb | regc;

	}

	// -----------MEMORY INSTRUCTIONS----------------------------
	// -----TWO REGISTERS, AND A MEMORY DISPLACEMENT IN BYTES----

	else if(func == 2)
	{
		if(instr.op1.operand == REGoperand)
		{
			rega = instr.op1.u.val;
			if((rega >= 0) && (rega < 32))
			{
				rega = rega << 21;
			}
			else
			{
				error("illegal register number");
			}
		}
		else
		{
			error("illegal, missing or extra operand");
		}


		if(instr.op2.operand == SYMoperand)
                {
                        if(symtabLookup(instr.op2.u.sym, &addr) == SUCCEED)
                        {
                                if(addr < 0)
                                {
                                        disp = ((-1 * addr) & 0xffff);
                                	symtabInstall(instr.op2.u.sym, (-1 * (offset + 1)));
                                }
                                else
                                {
                                        disp = ((4 * (addr)) & 0xffff);
                                }
                        }
                        else
                        {
                                symtabInstall(instr.op2.u.sym, (-1 * (offset + 1)));
                                disp = 0;
                        }
                }
		else if(instr.op2.operand != NULLoperand)
		{
			error("illegal, missing or extra operand");
		}

		if(instr.op3.operand == ICONSToperand)
		{
			disp = instr.op3.u.val;
			if(disp >= 65536 || disp <= -65536)
			{
				error("displacement (%x) overflows 16-bit field", disp);
			}
			disp = disp & 0xffff;
		}
		else if(instr.op3.operand != NULLoperand)
		{
			error("illegal, missing or extra operand");
		}

		if(instr.op4.operand == REGoperand)
		{
			regd = instr.op4.u.val;
			if((regd <= 31) && (regd >= 0))
			{
				regd = regd << 16;
			}
			else 
			{
				
				error("illegal register number");
			}
		}
		else
		{
			regd = 27;
			regd = regd << 16;
		}
	

		instruct = op | rega | disp | regd;
	}

	// -----------BRANCH INSTRUCTIONS---------------------------
	// -----------ONE REGISTER, AND BRANCH DISPLACEMENT IN LW---

	else if(func == 3)
	{
		if(instr.op1.operand == REGoperand)
		{
			rega = instr.op1.u.val;
			if((rega >= 0) && (rega <= 31))
			{
				rega = rega << 21;
			}
			else
			{
				error("illegal register number");
			}
		}
		else
		{
			error("illegal, missing or extra operand");
		}

		if(instr.op2.operand == ICONSToperand)
		{
			disp = instr.op2.u.val;
			if((disp >= 2097152) || (disp <= -2097152))
			{
				error("overflow of %x of 21-bit field", disp);
			}
		}
		else if(instr.op2.operand == SYMoperand)
		{
			if(symtabLookup(instr.op2.u.sym, &addr) == SUCCEED)
			{
				if(addr < 0)
				{
					disp = (addr * -1) & 0x1fffff;
					symtabInstall(instr.op2.u.sym, (-1 * (offset + 1))); 
				}
				else 
				{
					disp = ((addr - (offset + 1) & 0x001fffff));
				}
			}
			else 
			{
				symtabInstall(instr.op2.u.sym, (-1 * (offset + 1)));
				disp = 0;
			}
		}
		else
		{
			error("illegal, missing or extra operand");
		}

		if(instr.op3.operand != NULLoperand)
		{
			error("illegal, missing or extra operand");
		}
		
		if(instr.op4.operand != NULLoperand)
		{
			error("illegal, missing or extra operand");
		}

		instruct = op | rega | disp;
	}
	
	// -------------OPCODE WAS NOT AN INSTRUCTION--------
	if(func == 4)
	{
		return;
	}

	// --------------------Putting Instruct into buffer---------

	buffer[offset++] = instruct;
}

/*
 *        returnPointerToObjectCode
 *
 *        Return pointer to object code.
 */
void* returnPointerToObjectCode(void)
{
    return &buffer;
}

/*
 *        returnLengthOfObjectCode
 *
 *        Return length of object code.
 */
int returnLengthOfObjectCode(void)
{
    return (offset * 4);
}

/*
 *	This function should decode any opcode that is int the
 *
 *	specifications for the program.  If the instruction has a 
 * 
 *	NULL opcode it should set type equal to four which will do nothing.
 */

static int opcodedecoder(char *s, int *func)
{
	int bits = 0;

	if(s == NULL)
	{
		*func = 4;
		return 0;
	}
	if(strcmp(s, "addq") == 0)
	{
		bits = ((0x10 << 26) | (0x20 << 5));
		*func = 1;
	}
	else if(strcmp(s, "subq") == 0)
	{
		bits = ((0x10 << 26) | (0x29 << 5));
		*func = 1;
	} 
	else if(strcmp(s, "mulq") == 0)
	{
		bits = ((0x13 << 26) | (0x20 << 5));
		*func = 1;
	} 
	else if(strcmp(s, "cmpeq") == 0)
	{
		bits = ((0x10 << 26) | (0x2d << 5));
		*func = 1;
	} 
	else if(strcmp(s, "cmplt") == 0)
	{
		bits = ((0x10 << 26) | (0x4d << 5));
		*func = 1;
	} 
	else if(strcmp(s, "cmple") == 0)
	{
		bits = ((0x10 << 26) | (0x6d << 5));
		*func = 1;
	} 
	else if(strcmp(s, "and") == 0)
	{
		bits = ((0x11 << 26) | (0x00 << 5));
		*func = 1;
	} 
	else if(strcmp(s, "bis") == 0)
	{
		bits = ((0x11 << 26) | (0x20 << 5));
		*func = 1;
	} 
	else if(strcmp(s, "sll") == 0)
	{
		bits = ((0x12 << 26) | (0x39 << 5));
		*func = 1;
	} 
	else if(strcmp(s, "sra") == 0)
	{
		bits = ((0x12 << 26) | (0x3c << 5));
		*func = 1;
	}
	else if(strcmp(s, "lda") == 0)
	{
		bits = (0x08 << 26);
		*func = 2;
	} 
	else if(strcmp(s, "ldq") == 0)
	{
		bits = (0x29 << 26);
		*func = 2;
	} 
	else if(strcmp(s, "stq") == 0)
	{
		bits = (0x2d << 26);
		*func = 2;
	} 
	else if(strcmp(s, "beq") == 0)
	{
		bits = (0x39 << 26);
		*func = 3;
	} 
	else if(strcmp(s, "bne") == 0)
	{
		bits = (0x3d << 26);
		*func = 3;
	} 
	else if(strcmp(s, "br") == 0)
	{
		bits = (0x30 << 26);
		*func = 3;
	} 
	else if(strcmp(s, "jsr") == 0)
	{
		bits = ((0x1a << 26) | (0x1 << 14));
		*func = 2;
	} 
	else if(strcmp(s, "ret") == 0)
	{
		bits = ((0x1a << 26) | (0x2 << 14));
		*func = 2;
	} 
	else
	{
		error("unregonized opcode");
	}
	
	return bits;
}
