top:
	addq	$1,$2,$35
	mulq	$-1,$2,$3
	blah	$1,$2,$3
top:
	subq	$1,1024,$2
	addq	$1,-10,$2
	lda	$1,128000($2)
	ldq	$1,-128000($3)
	lda	$1,$2,$3
	bis	$1,100($2)
	jsr	$1,100($2)
	br	$1, stop
!exec
