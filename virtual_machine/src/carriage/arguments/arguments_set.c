/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 13:38:10 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/13 01:02:34 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_arguments.h"

void			_arguments_set_args_size(t_arguments *self)
{
	return;
}

void			arguments_set(t_arena *arena, int arena_position)
{
	t_arguments *self;

	self = arguments_singleton(ARGUMENTS_INSTANTIATE);
	self->arena_position = arena_position;
	self->op_code = arena_operation(arena, self->arena_position);
	if (self->op_code < OP_LIVE || OP_AFF < self->op_code)
	{
		self->is_correct_op_code = FALSE;
		return;
	}
	_arguments_set_types(self, arena);
	_arguments_is_match_op_code_and_types(self);
	_arguments_set_args_size(self);
	self->arg_1 = 1;
	self->arg_2 = 2;
	self->arg_3 = 3;
	return;
}
