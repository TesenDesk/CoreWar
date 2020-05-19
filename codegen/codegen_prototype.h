//
// Created by Jhiqui Jerde on 21/02/2020.
//

#ifndef CODEGEN_PROTOTYPE_H
#define CODEGEN_PROTOTYPE_H


#include "codegen.h"

#define CODEGEN_DEBUGGER 1
#define DIR_LEN_2 1
#define DIR_LEN_4 2

#define LABEL_WORD 99 //todo: need write what you need to do with it?


typedef struct		s_label_data
{
	char			*name;
	unsigned int	add;
}					t_label_data;

typedef union			u_code_addr
{
	void				*content;
	unsigned int		addr;
}						t_code_addr;


#endif //CODEGEN_PROTOTYPE_H
