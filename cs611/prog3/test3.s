instructions:
	beq	$0,bottom
	beq	$3,bottom
	bne	$7,bottom
	bne	$3,bottom
        br      $31,instructions
        br      $31,bottom
bottom:
!dump
