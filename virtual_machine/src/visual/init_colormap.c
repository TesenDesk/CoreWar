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
	tmp = *(arena->players);
	offset = 0;
	pos = offset;
	while (col <= arena->nb_players)
	{
		while (pos < offset + tmp->code_size)
			arena->colormap[pos++ % MEM_SIZE].cell_index = col;
		while (pos < offset + ofset_outer)
			arena->colormap[pos++ % MEM_SIZE].cell_index = NEUTRAL_COL;
		offset += ofset_outer;
		++col;
	}
	arena->color_is_set = 1;
}
