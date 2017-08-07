.name "toto"
.comment "test"

l2:		ldi 4, %-2, r2
		sti r2, 5, %:live
		and r1, %0, r1

live:	live %1
		zjmp %:live
