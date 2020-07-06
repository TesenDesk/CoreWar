/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_precheck_args.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 21:48:24 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/04 21:49:58 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

static int 	is_that_type()
{

}

int operation_precheck_args(t_carriage *self, t_op *op)
{
	char    arg_type_code;
	int     i;
	int     result;

        arg_type_code = (char)arena_get_n_bytes_from(self->arena,
	self->arena_position + ONE_BYTE, ONE_BYTE);
	result = SUCCESS;
	op->op_len = ONE_BYTE + ONE_BYTE;
	i = 0;
	while (i < op->args_num)
	{
		op->type_codes[i] = (arg_type_code >> (6 - 2 * i)) & TWO_BITS_MASK;
		if (op->type_codes[i] == REG_CODE)
		{
			op->args[i] = arena_get_n_bytes_from(self->arena,
				(self->arena_position + op->op_len), ONE_BYTE) - 1;
			op->op_len += ONE_BYTE;
			if (op->args[i] < 0 || op->args[i] >= 16)
				result = FAILURE;
		}
		else if (op->type_codes[i] == DIR_CODE)
		{
			op->args[i] = arena_get_n_bytes_from(self->arena,
				self->arena_position + op->op_len, op->t_dir_size);
			op->op_len += op->t_dir_size;
		}
		else if (op->type_codes[i] == IND_CODE)
		{
			op->args[i] = arena_get_n_bytes_from(self->arena,
				self->arena_position + op->op_len, TWO_BYTES);
			op->op_len += TWO_BYTES;
		}
		else
			result = FAILURE;
		i++;
	}
	return (result);
}
