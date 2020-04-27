/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _arena_set_smallest_unoccupied_name.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 23:07:38 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 23:08:07 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_arena.h"
/*
 *
 */
static void		_arena_set_smallest_unoccupied_name_postcondition_check(
					t_arena *self)
{
	if (self->smallest_unoccupied_name > self->nb_players)
		raise(__FILE__, __LINE__, EBADPLAYERNAME);
	return;
}

void		_arena_set_smallest_unoccupied_name(t_arena *self)
{
	int			new_player_name;

	new_player_name = self->smallest_unoccupied_name;
	while (
			(self->players)[new_player_name] != NULL &&
			new_player_name < self->nb_players)
		++new_player_name;
	self->smallest_unoccupied_name = new_player_name;
	_arena_set_smallest_unoccupied_name_postcondition_check(self);
	return;
}

