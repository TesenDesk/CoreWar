/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_colormap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:43:56 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/29 19:01:03 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_visual.h"

void				init_colormap(t_arena *arena, int ofset_outer)
{
	int	col;
	int	offset;
	int	pos;

	col = P_1_HOME;
	offset = 0;
	pos = offset;
	while (col <= arena_get_nb_players(arena))
	{
		while ((unsigned)pos < offset + arena_get_player_code_size(arena, col - 1))
			arena_set_cell_index(arena, pos++ % MEM_SIZE, col);
		while (pos < offset + ofset_outer)
			arena_set_cell_index(arena, pos++ % MEM_SIZE, NEUTRAL_COL);
		offset += ofset_outer;
		++col;
	}
	arena_set_color_is_set(arena, 1);
}
