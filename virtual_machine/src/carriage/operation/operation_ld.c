/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_ld.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:14:05 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/13 18:14:05 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

static void			print_op_log(t_carriage *self, int *args)
{
	if (vm_verbosity_lvl() & 4)
		printf("P %4i | ld %i r%i\n", self->num, args[ARG_1], args[ARG_2] + 1);
}

void				operation_ld(t_carriage *self)
{
	static			t_op op;

	op = g_op[OP_LD - 1];
	if (operation_precheck_args(self, &op) == SUCCESS)
	{
		if (op.type_codes[ARG_1] == IND_CODE)
			op.args[ARG_1] = arena_get_n_bytes_from(self->arena,
			self->arena_position + op.args[ARG_1] % IDX_MOD, REG_SIZE);
		print_op_log(self, op.args);
		if ((self->registers[op.args[ARG_2]] = op.args[ARG_1]) == 0)
			self->carry = TRUE;
		else
			self->carry = FALSE;
	}
	op.args_num = 600;
	self->arena_position = (self->arena_position + op.op_len) % MEM_SIZE;
}
