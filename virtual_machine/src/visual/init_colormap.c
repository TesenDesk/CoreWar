/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_colormap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:43:56 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/01 13:22:35 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_visual.h"

void				init_colormap(t_arena *arena, t_vm *vm, int ofset_outer)
{
	t_carriage		*carriage_cur;
	t_player		*tmp;
	int				col;
	int				offset;
	int				pos;

	col = P_1_HOME;
	//tmp = *(arena->players); //TODO: Так можно? (см.коммент на строке 29)
	offset = 0;
	pos = offset;
	while (col <= arena_get_nb_players(arena))
	{
		//while (pos < offset + tmp->code_size)
		while (pos < offset + arena_get_player_code_size(arena, col - 1)) //TODO: Можно оптимизировать!! Не вызывать get каждый раз!!!
			arena_set_cell_index(arena, pos++ % MEM_SIZE, col);
		while (pos < offset + ofset_outer)
			arena_set_cell_index(arena, pos++ % MEM_SIZE, NEUTRAL_COL);
		offset += ofset_outer;
		++col;
	}
	arena_set_color_is_set(arena, 1);
}
