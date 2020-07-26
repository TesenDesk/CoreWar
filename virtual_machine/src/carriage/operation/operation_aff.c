/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_aff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:18:31 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/13 18:22:17 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

void			operation_aff(t_carriage *self)
{
	t_op		aff;

	aff = g_op[OP_AFF - 1];
	if (operation_precheck_args(self, &aff) == SUCCESS
		&& aff.type_codes[ARG_1] == REG_CODE)
	{
		ft_printf("%c", self->registers[aff.args[ARG_1]]);
	}
	self->arena_position = (self->arena_position + aff.op_len) % MEM_SIZE;
}
