/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _vm_params_map_players_to_arena.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 00:07:15 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/09 00:08:37 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm_params.h"

void			_vm_params_map_players_to_arena(t_list *id_players,
						t_arena *arena, void (*arena_set_player)(t_arena *arena,
						t_player *new_player))
{
	t_player		*new_player;
	t_vmp_player	*curr_vmp_player;

	while (id_players != NULL)
	{
		curr_vmp_player = (t_vmp_player *)id_players->content;
		new_player = player_new(curr_vmp_player);
		(*arena_set_player)(arena, new_player);
		id_players = id_players->next;
	}
	return;
}
