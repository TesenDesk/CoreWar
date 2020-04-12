/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 13:38:10 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/12 17:54:30 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_arguments.h"

void			arguments_set(t_arena *arena, int arena_position,
					int carriage_op_code)
{
	t_arguments *self;

	self = arguments_singleton(ARGUMENTS_INSTANTIATE);
	self->op_code = arena_operation(arena, arena_position);

	if (
		self->op_code == OP_LIVE || self->op_code == OP_ZJMP ||
		self->op_code == OP_FORK || self->op_code == OP_LFORK)
		self->types = arena_argument_types(arena, arena_position);
	else
		self->types = NO_ARGUMENT_TYPES;
	arguments_set_if_operation_and_types_match(self);
	self->arg_1 = 1;
	self->arg_2 = 2;
	self->arg_3 = 3;
	return;
}
