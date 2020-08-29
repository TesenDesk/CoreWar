/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_aff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:18:31 by cmissy            #+#    #+#             */
/*   Updated: 2020/08/29 19:01:03 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

void			operation_aff(t_carriage *self)
{
	t_op		aff;

	aff = g_op[OP_AFF - 1];
	operation_precheck_args(self, &aff);
	self->arena_position = (self->arena_position + aff.op_len) % MEM_SIZE;
}
