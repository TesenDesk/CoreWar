.name		"Sliders"
.comment	"And the winner is ..."

		sti     r3,r8,r2
		add     r2,r4,r2
		xor     r13,r2,r7
		zjmp    %415
		ld      %0,r15
leon_ecrit:	zjmp    %:leon_live
roger:		ld	%0,r10
roger_live:	live	%42
		ldi	%:roger,r10,r11
		sti	r11,r12,r10
		add	r10,r4,r10
		xor	r6,r10,r7
		zjmp	%-361
		ld	%0,r15
roger_ecrit:	zjmp	%:roger_live
torp:		live	%42
		fork	%:leon
torp_:		live	%42
		fork	%:roger
		ld	%0,r15
		zjmp	%:torp
live:		live	%42
		live	%42
		live	%42
		live	%42
		live	%42
		live	%42
		live	%42
		live	%42
		live	%42
		live	%42
		live	%42
		live	%42
		live	%42
		live	%42
		live	%42
		live	%42
		live	%42
		live	%42
		live	%42
		live	%42
		live	%42
		live	%42
		live	%42
		live	%42
		zjmp	%:live
fork_live:	live	%42
		fork	%:live
		ld	%0,r15
		zjmp	%:fork_live











