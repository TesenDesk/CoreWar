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
	if (vm_verbosity_lvl() == 4)
	{
		printf("P %4i | add r%i r%i r%i\n",
		self->num, args[ARG_1] + 1, args[ARG_2] + 1, args[ARG_3] + 1);
	}
}

void            operation_add(t_carriage *self)
{
	static t_op	add;
	int			sum;

	add = g_op[OP_ADD - 1];
	if (operation_precheck_args(self, &add) == SUCCESS
		&& add.type_codes[ARG_1] == REG_CODE
		&& add.type_codes[ARG_2] == REG_CODE
		&& add.type_codes[ARG_3] == REG_CODE)
	{
		print_op_log(self, add.args);
		sum = self->registers[add.args[ARG_1]] + self->registers[add.args[ARG_2]];
		if ((self->registers[add.args[ARG_3]] = sum) == 0)
			self->carry = TRUE;
		else
			self->carry = FALSE;
	}
	self->arena_position = (self->arena_position + add.op_len) % MEM_SIZE;
}
