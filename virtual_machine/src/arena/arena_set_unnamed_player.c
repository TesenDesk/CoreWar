/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_ser_unnamed_player.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 19:00:07 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 23:08:48 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_arena.h"

void			arena_set_unnamed_player(t_arena *self,
					t_player *unnamed_player)
{
	_arena_set_smallest_unoccupied_name(self);
    player_set_name(unnamed_player, self->smallest_unoccupied_name);
	(self->players)[self->smallest_unoccupied_name] = unnamed_player;
	return;
}
