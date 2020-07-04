/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_set_unnamed_player.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 19:01:15 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/04 19:01:29 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_arena.h"

void			arena_set_unnamed_player(t_arena *self,
					t_player *unnamed_player)
{
	prvt_arena_set_smallest_unoccupied_name(self);
	player_set_name(unnamed_player, self->smallest_unoccupied_name);
	(self->players)[self->smallest_unoccupied_name] = unnamed_player;
	return ;
}
