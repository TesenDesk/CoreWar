//
// Created by Jhiqui Jerde on 21/02/2020.
//

#ifndef GIT_CODEGEN_PRIVATE_H
#define GIT_CODEGEN_PRIVATE_H

#include "codegen.h"

#include "token_defines.h"
#include "../virtual_machine/include/op.h"
#include "expr.h"
#include "expr_defines.h"
#define T_REG_CODE		1
#define T_DIR_CODE		2
#define T_IND_CODE		3


#define IND_PARAM_SIZE	2
#define DIR_PARAM_SIZE	4



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

typedef struct		s_codegen
{
	int				add;
	char			*code;
	char			*exec;
	unsigned int	code_size;
	int 			cur_instruction_addr;
	int 			cur_instruction_code;
	int 			cur_instruction_dirsize;
	t_hash_map		*labels_free;
	t_vector		*labels_ptrs;
	header_t		*header;
}					t_codegen;


typedef struct		s_label_data
{
	char			*name;
	unsigned int	add;
	unsigned int	instruction_begining;
	int 			size;
	int				param_type;
}					t_label_data;

typedef union			u_code_addr
{
	void				*content;
	unsigned int		addr;
}						t_code_addr;

#endif //GIT_CODEGEN_PRIVATE_H
