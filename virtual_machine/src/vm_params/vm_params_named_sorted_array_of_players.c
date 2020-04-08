/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_params_named_sorted_array_of_players.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 13:30:27 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/09 00:08:29 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm_params.h"

void				*vm_params_fill_and_sort_array_of_players(t_vm_params *self,
						t_arena *arena)
{
	_vm_params_map_players_to_arena(self->id_player_head, arena,
		arena_set_named_player);
	_vm_params_map_players_to_arena(self->noid_player_head, arena,
		arena_set_unnamed_player);
	return;
}
