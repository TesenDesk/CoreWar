.name 		"turtle"
.comment	"TURTLE FFS U LAMA"

entry:
	sti			r1, %:entry, %1

entry_l1:
	fork		%:entry_l1

################################################################################


ardef:
	live		%42
	zjmp		%:ardef

