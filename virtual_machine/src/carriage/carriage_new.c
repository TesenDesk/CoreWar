/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 20:36:25 by cmissy            #+#    #+#             */
/*   Updated: 2020/08/23 14:02:41 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_carriage.h"

t_carriage		*carriage_new(int p_name, t_arena *arena,
					int arena_position, int num)
{
	t_carriage	*self;

	if ((self = (t_carriage *)ft_memalloc(sizeof(*self))) == NULL)
		ft_raise(__FILE__, __LINE__, ENOMEMORY);
	self->num = num;
	self->arena = arena;
	self->player_name = p_name;
	self->registers[0] = -self->player_name;
	if (arena_position < 0)
		arena_position = MEM_SIZE + arena_position % MEM_SIZE;
	else if (arena_position >= MEM_SIZE)
		arena_position = arena_position % MEM_SIZE;
	self->arena_position = arena_position;
	self->was_store = 0;
	self->was_live = 0;
	self->stor_pos = 0;
	return (self);
}
