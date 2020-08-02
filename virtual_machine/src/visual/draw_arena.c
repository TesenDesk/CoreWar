/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:49:20 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/02 13:51:16 by ftothmur         ###   ########.fr       */
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
	rebuild_color_map(vm_get_arena(vm), vm);
	while (i < SQRT_MAP)
	{
		wmove(vm_get_wins(vm)->arena, i + 1, 1);
		while (j < SQRT_MAP)
		{
			col = chose_color(vm_get_arena(vm), (i * 64 + j) % MEM_SIZE, vm, i);
			wattron(vm_get_wins(vm)->arena, col);
			wprintw(vm_get_wins(vm)->arena, "%.2x",
				(unsigned char)vm_get_arena(vm)->data[(i * 64 + j++) % MEM_SIZE]);
			wattroff(vm_get_wins(vm)->arena, col);
			waddch(vm_get_wins(vm)->arena, ' ');
		}
		wprintw(vm_get_wins(vm)->arena, "\n");
		j = 0;
		++i;
	}
}
