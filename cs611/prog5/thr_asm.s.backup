 # Victor Michael Maloney CS 611 Prog 5
 # This assembly file contains helpers to C functions for a thread
 # library.  
 #
 # asm_yield takes to arguements the TCB to save the register from
 # and the TCB to load the registers to.  
.text
.globl asm_yield
asm_yield:
 #
 # This is the save registers We are saving to the TCB that is the first
 # arguement
 #
	stq $9, 0($16)
	stq $10, 8($16)
	stq $11, 16($16)
	stq $12, 24($16)
	stq $13, 32($16)
	stq $14, 40($16)
	stq $15, 48($16)
	stq $17, 144($16)
	stt $f2, 56($16)
	stt $f3, 64($16)
	stt $f4, 72($16)
	stt $f5, 80($16)
	stt $f6, 88($16)
	stt $f7, 96($16)
	stt $f8, 104($16)
	stt $f9, 112($16)
	stq $30, 120($16)
	stq $26, 128($16)
 #
 # Load the registers from the second arguement passed.
 #
        ldq $9, 0($17)
        ldq $10, 8($17)
        ldq $11, 16($17)
        ldq $12, 24($17)
        ldq $13, 32($17)
        ldq $14, 40($17)
        ldq $15, 48($17)
        ldt $f2, 56($17)
        ldt $f3, 64($17)
        ldt $f4, 72($17)
        ldt $f5, 80($17)
        ldt $f6, 88($17)
        ldt $f7, 96($17)
        ldt $f8, 104($17)
        ldt $f9, 112($17)
	ldq $16, 136($17)
 #
 # Fix the stack pointer and get the PC to the correct address.  Also
 # finally fix register 17.
 #
	ldq $30, 120($17)
	ldq $1, 128($17)
	ldq $17, 144($17)
 #
 # Jump to the new function.
 #
	jmp($1)
 #
 # This is the special yield that only takes a restore argument.
 #
.globl sp_yield
sp_yield:
 #
 # Fix the registers from memory.
 #
        ldq $9, 0($16)
        ldq $10, 8($16)
        ldq $11, 16($16)
        ldq $12, 24($16)
        ldq $13, 32($16)
        ldq $14, 40($16)
        ldq $15, 48($16)
        ldt $f2, 56($16)
        ldt $f3, 64($16)
        ldt $f4, 72($16)
        ldt $f5, 80($16)
        ldt $f6, 88($16)
        ldt $f7, 96($16)
        ldt $f8, 104($16)
        ldt $f9, 112($16)
	ldq $17, 144($16)
 #
 # Fix the stack pointer, PC, and finally register 16.
 #
	ldq $30, 120($16)
	ldq $1, 128($16)
	ldq $16, 136($16)
 #
 # Jump to new PC.
 #
	jmp ($1)
