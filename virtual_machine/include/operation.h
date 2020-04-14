/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:10:01 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/14 19:57:41 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATION_H
# define OPERATION_H

enum					e_op_code_groups
{
	OP_ERROR = -1,
	OP_LIFE,
	OP_AFFECT,
	OP_LOAD,
	OP_STORE,
	OP_LOAD_I,
	OP_STORE_I,
	OP_LOGIC,
	OP_ARITHMETIC,
};

enum				e_op_codes
{
	OP_MOCK,
	OP_LIVE,
	OP_LD,
	OP_ST,
	OP_ADD,
	OP_SUB,
	OP_AND,
	OP_OR,
	OP_XOR,
	OP_ZJMP,
	OP_LDI,
	OP_STI,
	OP_FORK,
	OP_LLD,
	OP_LLDI,
	OP_LFORK,
	OP_AFF,
	NUMBER_OF_OPERATIONS,
};

typedef struct s_carriage	t_carriage;
typedef						(*t_operation)(t_carriage *carriage);

#endif
