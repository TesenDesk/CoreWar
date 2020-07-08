/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_precheck_args.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:17:18 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/07 17:22:07 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

static int		is_correct_type_for_op(t_op *op, int i)
{
	static char	op_num[NUM_OF_ARG_TYPES];
	int			result;

	op_num[REG_CODE - 1] = T_REG;
	op_num[DIR_CODE - 1] = T_DIR;
	op_num[IND_CODE - 1] = T_IND;
	result = TRUE;
	if ((op_num[op->type_codes[i] - 1] & op->args_types[i]) == 0)
		result = FALSE;
	return (result);
}

static int		parse_the_arg(t_carriage *self, t_op *op, int i)
{
	int			result;

	result = SUCCESS;
	if (op->type_codes[i] == REG_CODE)
	{
		op->args[i] = arena_get_n_bytes_from(self->arena,
		(self->arena_position + op->op_len), T_REG_SIZE) - 1;
		if (op->args[i] < 0 || op->args[i] >= 16)
			result = FAILURE;
		op->op_len += T_REG_SIZE;
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
		self->arena_position + op->op_len, T_IND_SIZE);
		op->op_len += T_IND_SIZE;
	}
	else
		result = FAILURE;
	return (result);
}

int				operation_precheck_args(t_carriage *self, t_op *op)
{
	char		arg_type_code;
	int			i;
	int			result;
	static int	type_code_size = TYPE_CODE_SIZE;

	arg_type_code = (char)arena_get_n_bytes_from(
		self->arena, self->arena_position + OP_CODE_SIZE, type_code_size);
	op->op_len = OP_CODE_SIZE + type_code_size;
	result = SUCCESS;
	i = 0;
	while (i < op->args_num)
	{
		op->type_codes[i] = (arg_type_code >>
		(type_code_size * BITS_PER_BYTE - TWO_BITS * (i + 1))) & TWO_BITS_MASK;
		if (parse_the_arg(self, op, i) == FAILURE
		|| is_correct_type_for_op(op, i) == FALSE)
			result = FAILURE;
		i++;
	}
	return (result);
}
