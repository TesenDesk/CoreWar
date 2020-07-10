/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_add.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 21:30:45 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/04 21:37:52 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

static void		print_op_log(t_carriage *self, int *args)
{
	if (vm_verbosity_lvl() & 4)
	{
		printf("P %4i | add r%i r%i r%i\n",
		self->num, args[ARG_1] + 1, args[ARG_2] + 1, args[ARG_3] + 1);
	}
}

void            operation_add(t_carriage *self)
{
	t_op	op;
	int			sum;

	op = g_op[OP_ADD - 1];
	if (operation_precheck_args(self, &op) == SUCCESS)
	{
		print_op_log(self, op.args);
		sum = self->registers[op.args[ARG_1]] + self->registers[op.args[ARG_2]];
		if ((self->registers[op.args[ARG_3]] = sum) == 0)
			self->carry = TRUE;
		else
			self->carry = FALSE;
	}
	self->arena_position = (self->arena_position + op.op_len) % MEM_SIZE;
}
