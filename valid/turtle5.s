.name 		"turtle"
.comment	"TURTLE FFS U LAMA"

entry:
	sti			r1, %:zork, %1

zork:
	zjmp		%:zork

ardef:
	live		%42
	live		%42
	live		%42
	live		%42
	live		%42
	zjmp		%:zork

