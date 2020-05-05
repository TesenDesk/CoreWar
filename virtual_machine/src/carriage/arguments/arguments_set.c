/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 13:38:10 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/14 23:07:27 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_arguments.h"

void			_arguments_set_arg_1_size(t_arguments *self)
{
	if (((self->types | REG_FIRST) ^ REG_FIRST) == FALSE)
		self->arg_1_size = 1;
	else if (((self->types | IND_FIRST) ^ IND_FIRST) == FALSE)
		self->arg_1_size = 4;
	
	return;
}

void			_arguments_set_arg_2_size(t_arguments *self)
{
	return;
}

void			_arguments_set_arg_3_size(t_arguments *self)
{
	return;
}

void			_arguments_set_args_size(t_arguments *self)
{
	int			arg_types_size;
	
	arg_types_size = self->types == NO_ARGTYPES ? 0 : 1;
	_arguments_set_arg_1_size(self);
	_arguments_set_arg_2_size(self);
	_arguments_set_arg_3_size(self);
	self->code_size = OP_CODE_SIZE + arg_types_size + self->arg_1_size +
		self->arg_2_size + self->arg_3_size;
	return;
}

void			_arguments_set_nb_args(t_arguments *self)
{

	return;
}

void			arguments_set(t_arena *arena, int arena_position)
{
	t_arguments *self;

	self = arguments_singleton(ARGUMENTS_INSTANTIATE);
	self->arena_position = arena_position;
	self->op_code = arena_operation(arena, self->arena_position);
	_arguments_set_op_group(self);
	if (self->op_group == OP_ERROR)
		return;
	_arguments_set_types(self, arena);
	_arguments_set_if_op_code_and_types_match(self);
	if (self->are_match_operation_and_argument_types == FALSE)
		return;
	// _arguments_set_nb_args(self);
	_arguments_set_args_size(self);
	return;
}
