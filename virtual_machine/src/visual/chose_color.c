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
	int	ans;
	int	player_index;
	int	cell_index;

	(void)vm;
	(void)i;
	ans = 0;
	player_index = arena_get_player_index(arena, index % MEM_SIZE);
	cell_index = arena_get_cell_index(arena, index % MEM_SIZE);
	if (player_index == 0)
		ans = (COLOR_PAIR(cell_index));
	else if (player_index == cell_index && cell_index != NEUTRAL_COL)
		ans = (COLOR_PAIR(cell_index + HOME_OFFSET));
	else if (player_index != cell_index && cell_index != NEUTRAL_COL)
	{
		ans = (COLOR_PAIR(arena_get_cell_index(arena, index % MEM_SIZE) +
			OUT_OFFSET));
	}
	else if (player_index != cell_index && cell_index == NEUTRAL_COL)
		ans = (COLOR_PAIR(arena_get_cell_index(arena, index % MEM_SIZE)));
	else if (player_index == cell_index && cell_index == NEUTRAL_COL)
	{
		printf("dewfegjrifrseijgnfewiognserifbreisugbiweabguiersbgerjgvbersgv");
		exit(-1);
	}
	if (arena_get_store_index(arena, index % MEM_SIZE) == 1)
		ans |= WA_BOLD;
	return (ans);
}

/*
** TODO: что делает строка 36?
** TODO: *vm & i never used
** TODO: теоретически ans может быть возвращен неинициализированным
*/
