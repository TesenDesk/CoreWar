/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_windows.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:50:45 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/08 17:16:40 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_visual.h"

void		print_windows(t_vm *vm)
{
	if (!(arena_get_color_is_set(vm_get_arena(vm))))
	{
		init_colors();
		init_colormap(vm_get_arena(vm), vm, (MEM_SIZE /
			arena_get_nb_players(vm_get_arena(vm))));
	}
	draw_arena(vm);
	draw_basic_info(vm);
	draw_champ_info(vm);
	box(vm_get_wins(vm)->arena, 0, 0);
	box(vm_get_wins(vm)->info, 0, 0);
	box(vm_get_wins(vm)->champ, 0, 0);
	wrefresh(vm_get_wins(vm)->champ);
	wrefresh(vm_get_wins(vm)->arena);
	wrefresh(vm_get_wins(vm)->info);
}
