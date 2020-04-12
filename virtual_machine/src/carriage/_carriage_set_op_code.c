/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _carriage_set_op_code.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 17:31:54 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/12 17:52:28 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_carriage.h"

void			_carriage_set_op_code(t_carriage *self, t_arena *arena)
{
	self->op_code = arena_op_code(arena, self->arena_position);
	return;
}
