/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_windows.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:50:45 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/01 12:57:01 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_visual.h"

void		print_windows(t_vm *vm)
{
	if (!(arena_get_color_is_set(vm->arena)))
	{
		init_colors();
		init_colormap(vm->arena, vm, (MEM_SIZE / arena_get_nb_players(vm->arena)));
	}
	draw_arena(vm);
	draw_basic_info(vm);
	draw_champ_info(vm);
	box(vm->wins->arena, 0, 0);
	box(vm->wins->info, 0, 0);
	box(vm->wins->champ, 0, 0);
	wrefresh(vm->wins->champ);
	wrefresh(vm->wins->arena);
	wrefresh(vm->wins->info);
}
