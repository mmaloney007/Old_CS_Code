	addq	$10,$2,$3
	subq	$10,$2,$3
	addq	$10,2,$3
	subq	$10,255,$17
	mulq	$2,$3,$23
	cmpeq	$2,$3,$4
	cmpeq	$2,3,$4
	cmplt	$3,$2,$4
	cmplt	$3,0,$4
	cmple	$2,$31,$4
	and	$2,$3,$4
	bis	$2,$3,$4
	sll	$2,$3,$10
	sra	$2,33,$19
!dump
