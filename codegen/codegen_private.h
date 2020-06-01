//
// Created by Jhiqui Jerde on 21/02/2020.
//

#ifndef GIT_CODEGEN_PRIVATE_H
#define GIT_CODEGEN_PRIVATE_H

#include "codegen.h"

#define T_REG_CODE		1
#define T_DIR_CODE		2
#define T_IND_CODE		3



#define IND_PARAM_SIZE	2
#define DIR_PARAM_SIZE	4

typedef struct		s_codegen
{
	int				add;
	int				*code;
	char			*exec;
	unsigned int	code_size;
	t_hash_map		*labels_free;
	t_vector		*labels_ptrs;
	header_t		*header;
}					t_codegen;

//typedef struct		s_arg
//{
//	char			type;
//	void			*value;
//}					t_arg;
//
//typedef struct		s_expr
//{
//	char			type;
//	char			size;
//	void			*name;
//	t_arg			args[3];
//}					t_expr;

#endif //GIT_CODEGEN_PRIVATE_H
