/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chose_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:44:33 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/01 13:20:53 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_visual.h"


int		chose_color(t_arena *arena, int index, t_vm *vm, int i)
{
	int ans;


	if (arena->colormap[index % MEM_SIZE].player_index == 0)
		ans = (COLOR_PAIR(arena->colormap[index % MEM_SIZE].cell_index));
	else if (arena->colormap[index % MEM_SIZE].player_index ==
		arena->colormap[index % MEM_SIZE].cell_index)
		ans = (COLOR_PAIR(arena->colormap[index % MEM_SIZE].cell_index +
			HOME_OFFSET));
	else if (arena->colormap[index % MEM_SIZE].cell_index != NEUTRAL_COL)
	{
		ans = (COLOR_PAIR(arena->colormap[index % MEM_SIZE].cell_index +
			OUT_OFFSET));
	}
	else
		ans = (COLOR_PAIR(NEUTRAL_COL));
	if (arena->colormap[index % MEM_SIZE].store_index == 1)
		ans |= WA_BOLD;
	return (ans);
}
