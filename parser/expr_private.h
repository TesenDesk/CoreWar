
#ifndef EXPR_PRIVATE_H
#define EXPR_PRIVATE_H

#include "expr.h"

typedef struct		s_expr
{
	int				type;
	int				arg_size;
	int 			size;
	void			*name;
	t_arg			args[6];

	//изменить на индекс
}					t_expr;


//enum 				e_t_opcodes
//{
//	NO_OPCODE = 0,
//	OP_LIVE_CODE,
//	OP_LD_CODE,
//	OP_ST_CODE,
//	OP_ADD_CODE,
//	OP_SUB_CODE,
//	OP_AND_CODE,
//	OP_OR_CODE,
//	OP_XOR_CODE,
//	OP_ZJMP_CODE,
//	OP_LDI_CODE,
//	OP_STI_CODE,
//	OP_FORK_CODE,
//	OP_LLD_CODE,
//	OP_LLDI_CODE,
//	OP_LFORK_CODE,
//	OP_AFF_CODE,
//	OP_NUM_OF_CODES,
//};

#endif
