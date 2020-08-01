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

	//TODO: Можно оптимизировать вызовы get через общие переменные.
	if (arena_get_player_index(arena, index % MEM_SIZE) == 0)
		ans = (COLOR_PAIR(arena_get_cell_index(arena, index % MEM_SIZE)));
	else if (arena_get_player_index(arena, index % MEM_SIZE) ==
		arena_get_cell_index(arena, index % MEM_SIZE))
		ans = (COLOR_PAIR(arena_get_cell_index(arena, index % MEM_SIZE) +
			HOME_OFFSET));
	else if (arena_get_cell_index(arena, index % MEM_SIZE) != NEUTRAL_COL)
	{
		ans = (COLOR_PAIR(arena_get_cell_index(arena, index % MEM_SIZE) +
			OUT_OFFSET));
	}
	else
		ans = (COLOR_PAIR(NEUTRAL_COL));
	if (arena_get_store_index(arena, index % MEM_SIZE) == 1)
		ans |= WA_BOLD;
	return (ans);
}
