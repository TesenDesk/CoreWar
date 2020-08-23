/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:49:20 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/08 15:09:37 by ftothmur         ###   ########.fr       */
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
		wmove(vm->wins->arena, i + 1, 1);
		while (j < SQRT_MAP)
		{
			col = chose_color(vm_get_arena(vm), (i * 64 + j) % MEM_SIZE, vm, i);
			wattron(vm->wins->arena, col);
			wprintw(vm->wins->arena, "%.2x",
				arena_get_cell(vm_get_arena(vm), (i * 64 + j++) % MEM_SIZE));
			wattroff(vm->wins->arena, col);
			waddch(vm->wins->arena, ' ');
		}
		wprintw(vm->wins->arena, "\n");
		j = 0;
		++i;
	}
}

//TODO: Множественные расчеты одного значения, исправить на запись в оддну переменную
