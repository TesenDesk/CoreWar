/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_and.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:28:49 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/13 17:29:41 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

static void			print_op_log(t_carriage *self, int *args)
{
	if (vm_verbosity_lvl() & 4)
		printf("P %4i | and %i %i r%i\n", self->num, args[0], args[1],
		args[2] + 1);
}

void				operation_and(t_carriage *self)
{
	static t_op		and;

	and = g_op[OP_AND - 1];
	if (operation_precheck_args(self, &and) == SUCCESS)
	{
		if (and.type_codes[ARG_1] == REG_CODE)
			and.args[ARG_1] = self->registers[and.args[ARG_1]];
		else if (and.type_codes[ARG_1] == IND_CODE)
			and.args[ARG_1] = arena_get_n_bytes_from(self->arena,
					self->arena_position + and.args[ARG_1] % IDX_MOD, REG_SIZE);
		if (and.type_codes[ARG_2] == REG_CODE)
			and.args[ARG_2] = self->registers[and.args[ARG_2]];
		else if (and.type_codes[ARG_2] == IND_CODE)
			and.args[ARG_2] = arena_get_n_bytes_from(self->arena,
					self->arena_position + and.args[ARG_2] % IDX_MOD, REG_SIZE);
		print_op_log(self, and.args);
		if ((self->registers[and.args[ARG_3]] =
		and.args[ARG_1] & and.args[ARG_2]) == 0)
			self->carry = TRUE;
		else
			self->carry = FALSE;
	}
	self->arena_position = (self->arena_position + and.op_len) % MEM_SIZE;
}
