/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _carriage_set_if_op_code_is_correct.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 17:51:01 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/12 17:51:27 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_carriage.h"

void			_carriage_set_if_op_code_is_correct(t_carriage *self,
					t_arena *arena)
{
	self->is_correct_op_code = (self->op_code ==
		arena_op_code(arena, self->arena_position));
	return;
}
