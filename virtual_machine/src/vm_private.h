#ifndef VM_PRIVATE_H
# define VM_PRIVATE_H

/*
**	Limit individual processes in the allocated memory.
** 4 gibytes are all. Suppose that the program needs to have up to 256
** processes, the maximum for each is limited by this number.
*/

# define MAX_PROC_RAM		0xFFFFFF

#endif