/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_st.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:23:17 by cmissy            #+#    #+#             */
/*   Updated: 2020/08/01 17:33:24 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

static void			print_op_log(t_carriage *self, int *args, char *type_codes)
{
	if (vm_verbosity_lvl() & 4)
	{
		if (type_codes[1] == REG_CODE)
			ft_printf("P %4i | st r%i %i\n", self->num, args[ARG_1] + 1,
				args[ARG_2] + 1);
		else
			ft_printf("P %4i | st r%i %i\n", self->num, args[ARG_1] + 1,
			args[ARG_2]);
	}
}

void				operation_st(t_carriage *self)
{
	static t_op		op;

	op = g_op[OP_ST - 1];
	if (operation_precheck_args(self, &op) == SUCCESS)
	{
		print_op_log(self, op.args, op.type_codes);
		if (op.type_codes[ARG_2] == IND_CODE)
			arena_write_four_bytes_to_data(self->arena, self->arena_position
			+ op.args[ARG_2] % IDX_MOD, self->registers[op.args[ARG_1]]);
		else
			self->registers[op.args[ARG_2]] = self->registers[op.args[ARG_1]];
	}
	self->arena_position = (self->arena_position + op.op_len) % MEM_SIZE;
	self->was_store = TRUE;
	self->stor_pos = (self->arena_position + op.args[ARG_2] % IDX_MOD) % MEM_SIZE;
}
