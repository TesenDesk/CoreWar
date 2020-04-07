/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_params_named_sorted_array_of_players.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 13:30:27 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/07 14:53:13 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm_params.h"

void				*vm_params_fill_and_sort_array_of_players(t_vm_params *self,
						t_arena *arena)
{
	t_list			*curr_vmp_player_node;
	t_vmp_player	*curr_vmp_player;
	t_player		*new_player;

	curr_vmp_player_node = self->id_player_head;
	while (curr_vmp_player_node != NULL)
	{
		curr_vmp_player = (t_vmp_player *)curr_vmp_player_node->content;
		new_player = player_ctor(curr_vmp_player);
		arena_set_player(arena, new_player);
		curr_vmp_player_node = curr_vmp_player_node->next;
	}
	return;
}