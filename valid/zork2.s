.name "zork"
.comment "I'M ALIIIIVE"
loop:
        sti r1, %:live, %-1
live:
        live %0
