/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_ser_unnamed_player.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 19:00:07 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/07 19:51:38 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_arena.h"

static void		arena_set_smallest_unoccupied_name_postcondition_check(
					t_arena *self)
{
	if (self->smallest_unoccupied_name >= self->nb_players)
		raise(__FILE__, __LINE__, EBADPLAYERNAME);
	return;
}

static void		arena_set_smallest_unoccupied_name(t_arena *self)
{
	int			new_player_name;

	new_player_name = self->smallest_unoccupied_name;
	while (
			(self->players)[new_player_name] != NULL &&
			new_player_name < self->nb_players)
		++new_player_name;
	self->smallest_unoccupied_name = new_player_name;
	arena_set_smallest_unoccupied_name_postcondition_check(self);
	return;
}

void			arena_set_unnamed_player(t_arena *self,
					t_player *unnamed_player)
{
	arena_set_smallest_unoccupied_name(self);
	player_set_name(unnamed_player, self->smallest_unoccupied_name);
	(self->players)[self->smallest_unoccupied_name] = unnamed_player;
	return;
}
