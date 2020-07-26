/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_sti.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:14:53 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/13 17:16:26 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

static void			print_op_log(t_carriage *self, int *args)
{
	if (vm_verbosity_lvl() & 4)
	{
		printf("P %4i | sti r%i %i %i\n", self->num, args[0] + 1, args[ARG_2],
		args[ARG_3]);
		printf("       | -> store to %i + %i = %i (with pc and mod %i)\n",
		args[ARG_2], args[ARG_3], args[ARG_2] + args[ARG_3],
		self->arena_position + (args[ARG_2] + args[ARG_3]) % IDX_MOD);
	}
}

void				operation_sti(t_carriage *self)
{
	static t_op		op;
	int				position;

	op = g_op[OP_STI - 1];
	if (operation_precheck_args(self, &op) == SUCCESS)
	{
		if (op.type_codes[ARG_2] == REG_CODE)
			op.args[ARG_2] = self->registers[op.args[ARG_2]];
		else if (op.type_codes[1] == IND_CODE)
			op.args[ARG_2] = arena_get_n_bytes_from(self->arena,
			self->arena_position + op.args[ARG_2] % IDX_MOD, REG_SIZE);
		if (op.type_codes[ARG_3] == REG_CODE)
			op.args[ARG_3] = self->registers[op.args[ARG_3]];
		print_op_log(self, op.args);
		position = (self->arena_position + (op.args[ARG_2] + op.args[ARG_3])
		% IDX_MOD) % MEM_SIZE;
		arena_write_four_bytes_to_data(self->arena, position,
		self->registers[op.args[ARG_1]]);
	}
	self->arena_position = (self->arena_position + op.op_len) % MEM_SIZE;
	self->was_store = TRUE;
	self->stor_pos = position % MEM_SIZE;
}
