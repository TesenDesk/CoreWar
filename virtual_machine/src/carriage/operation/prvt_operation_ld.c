/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_ld.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 17:20:34 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/05 18:07:24 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_operation.h"

static void			print_op_log(t_carriage *self, int *args)
{
	printf("P %4i | ld %i r%i\n", self->num, args[ARG_1], args[ARG_2] + 1);
}

void operation_ld(t_carriage *self)
{
	const int		num_of_args_array[NUMBER_OF_OPERATIONS] = NUM_OF_ARGS_ARRAY;
	int				num_of_args = num_of_args_array[OP_LD];
	int				op_len;
	int				args[num_of_args];
	char			type_codes[num_of_args];

	if (operation_precheck_args(self, args, type_codes, num_of_args,
                                    &op_len) == SUCCESS
		&& (type_codes[ARG_1] == IND_CODE || type_codes[ARG_1] == DIR_CODE)
		&& type_codes[ARG_2] == REG_CODE)
	{
		if (type_codes[ARG_1] == IND_CODE)
			args[ARG_1] = arena_get_n_bytes_from(self->arena,
			self->arena_position + args[ARG_1] % IDX_MOD, FOUR_BYTES);
		print_op_log(self, args);
		if ((self->registers[args[ARG_2]] = args[ARG_1]) == 0)
			self->carry = TRUE;
		else
			self->carry = FALSE;
	}
	self->arena_position = (self->arena_position + op_len) % MEM_SIZE;
}
