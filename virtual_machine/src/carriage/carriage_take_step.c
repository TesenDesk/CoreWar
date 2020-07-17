/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage_take_step.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 20:38:37 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/14 15:45:50 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_carriage.h"

void		carriage_take_step(t_carriage *self)
{
	if (self->cycles_to_perform_op == 0)
	{
		prvt_carriage_set_op_code(self, self->arena);
		prvt_carriage_set_is_correct_op_code(self);
		prvt_carriage_set_cycles_to_perform_op(self);
	}
	if (self->cycles_to_perform_op > 0)
		self->cycles_to_perform_op -= 1;
	if (self->cycles_to_perform_op == 0)
	{
		if (self->is_correct_op_code)
			operation_dispatched(self);
		else
			self->arena_position = (self->arena_position + 1) % MEM_SIZE;
	}
}
