/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_codegen.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 20:54:51 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/19 16:08:05 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRVT_CODEGEN_H
# define PRVT_CODEGEN_H

# include "op.h"
# include "codegen.h"
# include "codegen_prototype.h"
# include "token.h"
# include "expr.h"

# define T_REG_CODE		1
# define T_DIR_CODE		2
# define T_IND_CODE		3

# define IND_PARAM_SIZE	2
# define DIR_PARAM_SIZE	4

enum				e_t_opcodes
{
	NO_OPCODE = 0,
	OP_LIVE_CODE,
	OP_LD_CODE,
	OP_ST_CODE,
	OP_ADD_CODE,
	OP_SUB_CODE,
	OP_AND_CODE,
	OP_OR_CODE,
	OP_XOR_CODE,
	OP_ZJMP_CODE,
	OP_LDI_CODE,
	OP_STI_CODE,
	OP_FORK_CODE,
	OP_LLD_CODE,
	OP_LLDI_CODE,
	OP_LFORK_CODE,
	OP_AFF_CODE,
	OP_NUM_OF_CODES,
};

typedef struct		s_codegen
{
	int				add;
	char			*code;
	char			*exec;
	unsigned int	code_size;
	int				cur_instruction_addr;
	int				cur_instruction_code;
	int				cur_instruction_dirsize;
	t_hash_map		*labels_free;
	t_vector		*labels_ptrs;
	t_header		*header;
	t_vector        *junk_container;
}					t_codegen;

#endif
