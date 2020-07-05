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

#include "prvt_operation.h"

static int		t_dir_size_for_the_op(int op_code)
{
	static int	t_dir_sizes[NUMBER_OF_OPERATIONS] =
	{0, 4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 4, 2, 2, 4};
	return (t_dir_sizes[op_code]);
}

int operation_precheck_args(t_carriage *self, int *args,
							char *type_codes, int num_of_args, int *op_len)
{
	char		argument_type_code;
	int			i;
	int			result;
	int			t_dir_size;

	argument_type_code = (char)arena_get_n_bytes_from(self->arena,
	self->arena_position + ONE_BYTE, ONE_BYTE);
	result = SUCCESS;
	*op_len = ONE_BYTE + ONE_BYTE;
	t_dir_size = t_dir_size_for_the_op(self->op_code);
	i = 0;
	while (i < num_of_args)
	{
		type_codes[i] = (argument_type_code >> (6 - 2 * i)) & TWO_BITS_MASK;
		if (type_codes[i] == REG_CODE)
		{
			args[i] = arena_get_n_bytes_from(self->arena,
				(self->arena_position + *op_len), ONE_BYTE) - 1;
			*op_len += ONE_BYTE;
			if (args[i] < 0 || args[i] >= 16)
				result = FAILURE;
		}
		else if (type_codes[i] == DIR_CODE)
		{
			args[i] = arena_get_n_bytes_from(self->arena,
				self->arena_position + *op_len, t_dir_size);
			*op_len += t_dir_size;
		}
		else if (type_codes[i] == IND_CODE)
		{
			args[i] = arena_get_n_bytes_from(self->arena,
				self->arena_position + *op_len, TWO_BYTES);
			*op_len += TWO_BYTES;
		}
		else
		{
			result = FAILURE;
			args[i] = 0;
		}
		i++;
	}
	return (result);
}
