/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_operation_or.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 21:43:39 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/04 21:44:48 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_operation.h"

static void		print_op_log(t_carriage *self, int *args)
{
	if (vm_verbosity_lvl() == 4)
		printf("P %4i | or %i %i r%i\n", self->num, args[ARG_1],
		args[ARG_2], args[ARG_3] + 1);
}

static void		convert_args(t_carriage *self, int *args, char *type_codes)
{
	if (type_codes[ARG_1] == CODE_T_REG)
		args[ARG_1] = self->registers[args[ARG_1]];
	else if (type_codes[ARG_1] == CODE_T_IND)
		args[ARG_1] = arena_get_n_bytes_from(self->arena,
		self->arena_position + args[ARG_1] % IDX_MOD, FOUR_BYTES);
	if (type_codes[ARG_2] == CODE_T_REG)
		args[ARG_2] = self->registers[args[ARG_2]];
	else if (type_codes[ARG_2] == CODE_T_IND)
		args[ARG_2] = arena_get_n_bytes_from(self->arena,
		self->arena_position + args[ARG_2] % IDX_MOD, FOUR_BYTES);
}

void			prvt_operation_or(t_carriage *self)
{
	int			op_len;
	int			args[THREE_ARGS];
	char		type_codes[THREE_ARGS];

	if (prvt_operation_precheck_args(self, args, type_codes, THREE_ARGS,
	&op_len) == SUCCESS
		&& (type_codes[ARG_1] == CODE_T_REG || type_codes[ARG_1] == CODE_T_DIR
			|| type_codes[ARG_1] == CODE_T_IND)
		&& (type_codes[1] == CODE_T_REG || type_codes[1] == CODE_T_DIR
			|| type_codes[1] == CODE_T_IND)
		&& type_codes[2] == CODE_T_REG)
	{
		convert_args(self, args, type_codes);
		print_op_log(self, args);
		if ((self->registers[args[ARG_3]] = args[ARG_1] | args[ARG_2]) == 0)
			self->carry = TRUE;
		else
			self->carry = FALSE;
	}
	self->arena_position = (self->arena_position + op_len) % MEM_SIZE;
}
