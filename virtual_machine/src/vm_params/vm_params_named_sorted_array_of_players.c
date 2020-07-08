/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_params_named_sorted_array_of_players.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 13:30:27 by yurezz            #+#    #+#             */
/*   Updated: 2020/07/02 18:57:39 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arena/prvt_arena.h>
#include "prvt_vm_params.h"
#include "../player/prvt_player.h"

static void			prvt_vm_params_map_players_to_arena(t_list *id_players,
						t_arena *arena, void (*arena_set_player)(t_arena *arena,
						t_player *new_player))
{
	t_player		*player;

	while (id_players != NULL)
	{
		player = player_new(id_players->content);
		(*arena_set_player)(arena, player);
		id_players = id_players->next;
	}
	return ;
}

void				vm_params_fill_and_sort_array_of_players(t_vm_params *self,
						t_arena *arena)
{
	if (self->id_player_head != NULL)
		prvt_vm_params_map_players_to_arena(self->id_player_head, arena,
		arena_set_named_player);
	if (self->noid_player_head != NULL)
		prvt_vm_params_map_players_to_arena(self->noid_player_head, arena,
		arena_set_unnamed_player);
	return ;
}
