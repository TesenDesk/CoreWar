.name "zork"
.comment "I'M ALIIIIVE"

l2:

l3:
l4:

l5:sti r1, %:live, %1
		and r1, %0, r1
live:
	live %1
		zjmp %:live

dive:
dive2:
