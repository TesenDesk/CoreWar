/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_players_introducing.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 19:15:35 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/04 19:16:05 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_arena.h"

void		arena_players_introducing(t_arena *self)
{
	int		index;

	ft_printf("Introducing contestants...\n");
	index = 0;
	while (index < self->nb_players)
	{
		player_introducing(self->players[index]);
		++index;
	}
	return ;
}
