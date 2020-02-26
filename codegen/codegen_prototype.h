//
// Created by Jhiqui Jerde on 21/02/2020.
//

#ifndef CODEGEN_PROTOTYPE_H
#define CODEGEN_PROTOTYPE_H

#include "libft.h"

#define CG_STATE_UNDEFINED -1
#define CG_STAGE_INIT 0
#define CG_STAGE_SETLABEL 1
#define CG_STAGE_GETLABEL 2
#define CG_STAGE_UNKNOWN 99

typedef enum			e_commands
{
	COM_LIVE = 1,
	COM_LD,
	COM_ST,
	COM_ADD,
	COM_SUB,
	COM_AND,
	COM_OR,
	COM_XOR,
	COM_ZJMP,
	COM_LDI,
	COM_STI,
	COM_FORK,
	COM_LLD,
	COM_LLDI,
	COM_LFORK,
	COM_AFF
}						t_commands;

#endif //CODEGEN_PROTOTYPE_H
