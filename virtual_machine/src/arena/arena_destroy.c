/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 23:05:26 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 23:05:52 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_arena.h"
#include "player.h"

static void         players_destroy(t_arena *self) {
    int         i;
    t_player    **players;

    i = 0;
    players = self->players;
    while (i < self->nb_players)
    {
        player_destroy(&players[i]);
        ++i;
    }
    free(self->players);
}

void				arena_destroy(t_arena **self)
{
    int     c;

    c = 0;

	players_destroy(*self);
	ft_memdel((void **)self);
	return;
}
