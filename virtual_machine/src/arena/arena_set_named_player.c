/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_set_named_player.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 19:00:31 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/07 20:12:52 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_arena.h"

void		arena_set_named_player(t_arena *self, t_player *named_player)
{
	int		name;

	name = player_name(named_player);
	if (self->players[name] != NULL)
		raise(__FILE__, __LINE__, EDOUBLENAME);
	self->players[name] = named_player;
	return;
}
