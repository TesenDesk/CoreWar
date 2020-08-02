/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:49:20 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/01 13:17:30 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_visual.h"

void		draw_arena(t_vm *vm)
{
	int		sqr;
	int		i;
	int		j;
	int		col;

	i = 0;
	j = 0;
	rebuild_color_map(vm->arena, vm);
	while (i < SQRT_MAP)
	{
		wmove(vm->wins->arena, i + 1, 1);
		while (j < SQRT_MAP)
		{
			col = chose_color(vm->arena, (i * 64 + j) % MEM_SIZE, vm, i);
			wattron(vm->wins->arena, col);
			wprintw(vm->wins->arena, "%.2x",
				(unsigned char)arena_get_data_by_address(vm->arena, (i * 64 + j++) % MEM_SIZE));//vm->arena->data[(i * 64 + j++) % MEM_SIZE]);
			wattroff(vm->wins->arena, col);
			waddch(vm->wins->arena, ' ');
		}
		wprintw(vm->wins->arena, "\n");
		j = 0;
		++i;
	}
}
