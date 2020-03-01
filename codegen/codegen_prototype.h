//
// Created by Jhiqui Jerde on 21/02/2020.
//

#ifndef CODEGEN_PROTOTYPE_H
#define CODEGEN_PROTOTYPE_H

#include "libft.h"
#include "junk/op.h"

#define CODEGEN_DEBUGGER 1
#define DIR_LEN_2 1
#define DIR_LEN_4 2

#define LABEL_WORD 99 //todo: need write what you need to do with it?

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
