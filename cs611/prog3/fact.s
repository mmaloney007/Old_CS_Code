 #
 # This is Alpha assembler source code for computing the factorial function.
 #
 # The code is based on MIPS code from pages A-26 and A-27 of Patterson &
 # Hennessy.
 #
 # It computes fact(10).
 #
	subq	$sp,16,$sp	# Stack frame is 16 bytes long
	stq	$26,0($sp)	# Save return address
 #
	addq	$31,10,$16	# Put argument (10) in arg 0 register
	lda	$1,fact		# Call factorial function
	jsr	$26,($1)
 #
 #
	ldq	$26,0($sp)	# Restore return address
	addq	$sp,16,$sp	# Pop stack frame
	ret	$31,($26)	# Return to caller
 #
 #
 # The factorial function itself
 #
 # it assumes its single argument is an unsigned integer.
 #
fact:
	subq	$sp,16,$sp	# Stack frame is 16 bytes long
	stq	$26,0($sp)	# Save return address
 #
	stq	$16,8($sp)	# Save argument (n)
 #
	bne	$16,L2		# Branch if n > 0
	addq	$31,1,$0	# Return 1
	br	$31,L1		# Jump to code to return
 #
L2:
	subq	$16,1,$16	# Compute n - 1
	lda	$1,fact		# Recursive call (passing n - 1)
	jsr	$26,($1)
 #
	ldq	$3,8($sp)	# Load n
	mulq	$0,$3,$0	# Compute fact(n-1) * n
 #
L1:				# Result is in int return register ($0)
	ldq	$26,0($sp)	# Restore return address
	addq	$sp,16,$sp	# Pop stack frame
	ret	$31,($26)	# Return to caller
!exec
