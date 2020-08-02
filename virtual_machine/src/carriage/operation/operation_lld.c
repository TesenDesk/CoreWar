/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_lld.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:17:58 by cmissy            #+#    #+#             */
/*   Updated: 2020/08/01 18:42:40 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

static void			print_op_log(t_carriage *self, int *args)
{
	if (vm_verbosity_lvl() & 4)
		ft_printf("P %4i | lld %i r%i\n", self->num, args[ARG_1], args[ARG_2] + 1);
}

void				operation_lld(t_carriage *self)
{
	static t_op		op;

	op = g_op[OP_LLD - 1];
	if (operation_precheck_args(self, &op) == SUCCESS)
	{
		if (op.type_codes[ARG_1] == IND_CODE)
			op.args[ARG_1] = arena_get_n_bytes_from(self->arena,
			self->arena_position + op.args[ARG_1], REG_SIZE / 2);
		print_op_log(self, op.args);
		if ((self->registers[op.args[ARG_2]] = op.args[ARG_1]) == 0)
			self->carry = TRUE;
		else
			self->carry = FALSE;
	}
	self->arena_position = (self->arena_position + op.op_len) % MEM_SIZE;
}
