/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _arguments_set_types.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 01:02:17 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/13 01:02:28 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_arguments.h"

void			_arguments_set_types(t_arguments *self, t_arena *arena)
{
	if (_arguments_op_code_is_op_life(self) == FALSE)
		self->types = arena_argument_types(arena, self->arena_position);
	else
		self->types = NO_ARGTYPES;
	return;
}
