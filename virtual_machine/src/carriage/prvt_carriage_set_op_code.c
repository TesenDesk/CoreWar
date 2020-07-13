/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_carriage_set_op_code.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 21:03:04 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/04 21:08:19 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_carriage.h"

void			prvt_carriage_set_op_code(t_carriage *self, t_arena *arena)
{
	self->op_code = arena_op_code(arena, self->arena_position);
	return ;
}
