//Victor Maloney CS 611 Assignment 4
/*
 * This file implements the dynamic linker for this program.  It uses a
 * temporary PLT table to append the one in the object file to the old PLT
 * table.  It fixes the address of the procedures in memory for both and
 * the puts them together.  After that it changes the pointer.
 */

#include <stdio.h>
#include <stdlib.h>
#include "DL.h"

void dynamicLinker(PLTentry* e)
{
	FILE *f; //--file variable----------------
	int a = 0; //--counter int for "for" loops---
	int b = 0; //--counter int for "for" loops---
	long entrees = 0; //--number of entrees in object file---
	long stat = 0; //--the status of the entree in object file---
	long addr = 0; //--offset gotten from object file---
	long len=0; //--length of code in object file---
	long variable1 = 0;  //--helper variable for object file extraction--
	long variable2 = 0;  //--helper variable for object file extraction--
	long *leng2; //--helps set correct address---------
	char *leng;  //--helps set correct address---------	
	char *caller; //--becomes the name of the procedure that called
	char c; //--helps in object file extractoin-----------
	char *procedure; //--temporarily the name of the procedure in obj file
	char *fileName; //--name of file where the procedure in obj file is
	char *code; //--pointer to code in memory
	char *add; //--helps set correct address--------
	PLTentry *filePLT; //---becomes the PLT table of the obj. file----
	PLTentry *newPLT;  //---becomes the new PLT---
	PLTentry tmp;  //----temporary holder for the PLT---------
	
	//---A union to help in casting------
	union {
		void (*point)(void);
		long addr;
	} u;

	caller = e -> procedureName;	

	if(e ->status == PLT_INSYMBOL)
	{
		printf("error PLT_INSYMBOL\n");
	}

	if((f = fopen((e -> objectFileName), "r")) == NULL)
	{
		printf("error opening object file\n");
	}

	//---------reading in the object file--------------

	for(a = 0;a < 8;a++)
	{
		c = getc(f);
		c = c << (a*8);
		entrees = entrees | c;
	}
	
	filePLT = malloc((sizeof(PLTentry) * entrees));
	if(filePLT == NULL)
	{
		fprintf(stderr, "No memory for object file PLT\n");
	}

	for(b = 0;b < entrees;b++)
	{ 	
		
		procedure = malloc(256);
		if(procedure == NULL)
		{
			fprintf(stderr, "No memory for procedure name\n");
		}

		a = 0;
		stat = 0;
		addr = 0;
		variable1 = 0;
		variable2 = 0;
		c = getc(f);
		while(c != 0)
		{
			procedure[a++] = c;
			c = getc(f);
		}
		procedure[a] = '\0';
	
		fileName = malloc(256);
		if(fileName == NULL)
		{
			fprintf(stderr, "No memory for object file name\n");
		}
		
		a = 0;
		c = getc(f);
		while(c != 0)
		{
			fileName[a++] = c;
			c = getc(f);
		}
		fileName[a] = '\0';
	
		for(a = 0;a < 8;a++)
		{
			c = getc(f);
			variable1 = c | variable1;
			variable1 = variable1 & (0xff << (a*8)); 	
			variable1 = variable1 << (a*8);
			stat = stat | variable1;
			variable1 = 0;
		}
	
		for(a = 0;a < 8;a++)
		{
			c = getc(f);
			variable2 = c | variable2;
			variable2 = variable2 & (0xff << (a*8)); 	
			variable2 = variable2 << (a*8);
			addr = addr | variable2;
			variable2 = 0;
		}

		tmp.procedureName = procedure;
		tmp.objectFileName = fileName;
		u.addr = addr;
		tmp.procedureAddress = u.point;
		tmp.status = stat; 	

		filePLT[b] = tmp;
	}

	//---Gets the length of the object code in the file---------
	
	for(a = 0;a < 8;a++)
	{
		c = getc(f);
		variable1 = c | variable1;
		variable1 = variable1 & (0xff << (a*8)); 	
		len = len | variable1;
		variable1 = 0;
	}
	
	
	code = malloc(len);
	if(code == NULL)
	{
		fprintf(stderr, "No memory for code in memory\n");
	}

	for(a = 0;a < len;a++)
	{
		code[a] = getc(f);
	}
	
	fclose(f);

	//--Fixes the addresses in memory to either DLstub or the correct-----
	//-------address in memory--------------------------------------------

	for(a = 0;a < entrees;a++)
	{
		if(filePLT[a].status == PLT_INSYMBOL)
		{
			u.addr = *(long *)(&filePLT[a].procedureAddress) + *(long *)&code;
			filePLT[a].procedureAddress = u.point;
		}
		if(filePLT[a].status == PLT_OUTSYMBOL)
		{
			filePLT[a].procedureAddress = &DLstub;
		}	
	}

	//-----fixes the quadwords in memory before the code---------------

	for(a = 0;a < entrees;a++)
	{	
		if(filePLT[a].status == PLT_INSYMBOL)
		{
			add = (char *)(filePLT[a].procedureAddress);
			add = add - 8;
			*((PLTentry ***)add) = &PLT;
			leng = (char *)(filePLT[a].procedureAddress);
			leng = leng - 16;
			leng2 = (long *)leng;
			*leng2 = PLTlength; 		
		}
	}
	
	//-----Makes sure the PLT tables are both correct-----------------

	for(a = 0;a < PLTlength;a++)
	{
		for(b = 0;b < entrees;b++)
		{
			if(strcmp((PLT[a].procedureName),(filePLT[b].procedureName)) == 0)
			{
				if(PLT[a].status == PLT_INSYMBOL && filePLT[b].status == PLT_INSYMBOL)
				{
					fprintf(stderr, "error two insymbols in PLT table\n");
				}	
				
				else if(PLT[a].status == PLT_INSYMBOL && filePLT[b].status == PLT_OUTSYMBOL)
				{
					filePLT[b].procedureAddress = PLT[a].procedureAddress;
					filePLT[b].status = PLT_INSYMBOL;
					*(filePLT[b].objectFileName) = '\0';
				}
				
				else if(PLT[a].status == PLT_OUTSYMBOL && filePLT[b].status == PLT_INSYMBOL)
				{
					PLT[a].procedureAddress = filePLT[b].procedureAddress; 
					PLT[a].status = PLT_INSYMBOL;
					*(PLT[a].objectFileName) = '\0';
				}
			}
		}
	}
	
	//------Puts both PLT tables into newPLT table------------------------

	newPLT = malloc(sizeof(PLTentry) * (PLTlength + entrees));
	if(newPLT == NULL)
	{
		fprintf(stderr, "No memory for newPLT/n");
	}
	
	for(a = 0;a < PLTlength;a++)
	{
		newPLT[a] = PLT[a];
	}
			
	for(a = 0;a < entrees;a++)
	{
		newPLT[a + PLTlength] = filePLT[a];
	}

	if(PLTstatus == PLT_DYNAMIC_TABLE)
	{
		free(PLT);
		PLT = newPLT;
	}
	else
	{
		PLT = newPLT;
		PLTstatus = PLT_DYNAMIC_TABLE;
	}

	PLTlength = PLTlength + entrees;
			
	a = 0;
	while(strcmp((PLT[a].procedureName), caller) != 0)
	{
		a++;
	}

	(*(PLT[a].procedureAddress))();
}
