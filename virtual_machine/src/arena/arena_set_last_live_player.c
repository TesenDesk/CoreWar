/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_set_last_live_player.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 19:01:57 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/04 19:02:12 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_arena.h"

void		arena_set_last_live_player(t_arena *self, int player_num)
{
	if (player_num > 0 && player_num <= self->nb_players)
	{
		self->last_live_player = player_num;
		player_live_verbosity(self->players[player_num - 1]);
	}
}
