.name "toto"
.comment "test"

l2:		lldi r1, %5, r2
		st r2, 46
		and r1, %0, r1

live:	live %1
		zjmp %:live
