/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_set_named_player.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 19:00:31 by yurezz            #+#    #+#             */
/*   Updated: 2020/07/04 18:43:25 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_arena.h"

void		arena_set_named_player(t_arena *self, t_player *named_player)
{
	int		name;

	name = player_name(named_player);
	if (name > self->nb_players || name < 1)
		raise(__FILE__, __LINE__, EBADPLAYERNAME);
	if (self->players[name - 1] != NULL)
		raise(__FILE__, __LINE__, EDOUBLENAME);
	self->players[name - 1] = named_player;
	return ;
}
