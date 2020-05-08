/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_params_named_sorted_array_of_players.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita_toropov <nikita_toropov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 13:30:27 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/26 21:40:16 by nikita_toro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm_params.h"
#include "player.h"

//static void			arena_set_player(t_arena *arena, t_player *new_player)
//{
//	char 			*
//}

static void			_vm_params_map_players_to_arena(t_list *players,
						t_arena *arena, void (*arena_set_player)(t_arena *arena,
						t_player *new_player))
{

	while (players != NULL)
	{
		(*arena_set_player)(arena, player_new(players->content));
		players = players->next;
	}
	return ;
}

void				vm_params_fill_and_sort_array_of_players(t_vm_params *self,
						t_arena *arena)
{
	if (self->id_player_head != NULL)
		_vm_params_map_players_to_arena(self->id_player_head, arena,
		arena_set_named_player);
	if (self->noid_player_head != NULL)
		_vm_params_map_players_to_arena(self->noid_player_head, arena,
		arena_set_unnamed_player);
	return;
}
