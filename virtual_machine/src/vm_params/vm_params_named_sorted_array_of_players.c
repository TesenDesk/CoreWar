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

static void			_vm_params_map_players_to_arena(t_list *id_players,
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

void				*vm_params_fill_and_sort_array_of_players(t_vm_params *self,
						t_arena *arena)
{
	_vm_params_map_players_to_arena(self->id_player_head, arena,
		arena_set_named_player);
	_vm_params_map_players_to_arena(self->noid_player_head, arena,
		arena_set_unnamed_player);
	return;
}
