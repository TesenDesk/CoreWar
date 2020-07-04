/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_operation_add.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 21:30:45 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/04 21:37:52 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_operation.h"

static void		print_op_log(t_carriage *self, int *args)
{
	if (vm_verbosity_lvl() == 4)
	{
		printf("P %4i | add r%i r%i r%i\n",
		self->num, args[0] + 1, args[1] + 1, args[2] + 1);
	}
}

void			prvt_operation_add(t_carriage *self)
{
	int         num_of_args = prvt_op_num_of_args(self->op_code);
	int			op_len;
	int			args[num_of_args];
	char		type_codes[num_of_args];
	int			sum;

	if (prvt_operation_precheck_args(self, args, type_codes,
			num_of_args, &op_len) == SUCCESS
		&& type_codes[ARG_1] == CODE_T_REG
		&& type_codes[ARG_2] == CODE_T_REG
		&& type_codes[ARG_3] == CODE_T_REG)
	{
		print_op_log(self, args);
		sum = self->registers[args[ARG_1]] + self->registers[args[ARG_2]];
		if ((self->registers[args[ARG_3]] = sum) == 0)
			self->carry = TRUE;
		else
			self->carry = FALSE;
	}
	self->arena_position = (self->arena_position + op_len) % MEM_SIZE;
}
