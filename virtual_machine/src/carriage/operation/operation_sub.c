/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:21:37 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/13 17:22:25 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

static void			print_op_log(t_carriage *self, int *args)
{
	if (vm_verbosity_lvl() & 4)
	{
		printf("P %4i | sub r%i r%i r%i\n", self->num, args[ARG_1] + 1,
		args[ARG_2] + 1, args[ARG_3] + 1);
	}
}

void				operation_sub(t_carriage *self)
{
	static t_op		op;
	int				sub;

	op = g_op[OP_SUB - 1];
	if (operation_precheck_args(self, &op) == SUCCESS)
	{
		print_op_log(self, op.args);
		sub = self->registers[op.args[ARG_1]] - self->registers[op.args[ARG_2]];
		if ((self->registers[op.args[ARG_3]] = sub) == 0)
			self->carry = TRUE;
		else
			self->carry = FALSE;
	}
	self->arena_position = (self->arena_position + op.op_len) % MEM_SIZE;
}
