 #
 # This function is called when the dynamic linker is required.
 # It looks for the address of the PLT entry, which caused the linker
 # to be called, at -8($sp). It calls the dynamic linker, passing
 # the PLT entry address as the only argument.
 #
	.globl	DLstub
	.ent	DLstub
	.frame	$sp,16,$26
DLstub:
	ldgp	$29,($27)
	ldq		$16,-8($sp)
	subq	$sp,16,$sp
	stq		$26,0($sp)
	.prologue 1
	jsr		$26,dynamicLinker
	ldq		$26,0($sp)
	addq	$sp,16,$sp
	ret
	.end
