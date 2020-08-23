/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_basic_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:46:53 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/23 15:49:00 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_visual.h"

void			draw_basic_info(t_vm *vm)
{
	t_wins		*info_win;

	info_win = vm_get_wins(vm);
	wattron(info_win->info, COLOR_PAIR(B_INFO) | A_BOLD);
	wmove(info_win->info, 1, 1);
	wprintw(info_win->info, " CYCLES_TO_DIE:   %zu\n",
		vm_get_cycles_to_die(vm));
	wmove(info_win->info, 2, 1);
	wprintw(info_win->info, " CURRENT_COUNTER: %zu\n",
		vm_get_c_counter(vm));
	wmove(info_win->info, 3, 1);
	wprintw(info_win->info, " GLOBAL_COUNTER:  %d\n",
		vm_get_global_counter(vm));
	wmove(info_win->info, 4, 1);
	wprintw(info_win->info, " CYCLES_DELTA:    %d\n", CYCLE_DELTA);
	wmove(info_win->info, 5, 1);
	wprintw(info_win->info, " GAME_SPEED:      %d\n", vm_get_speed(vm));
	wmove(info_win->info, 6, 1);
	wprintw(info_win->info,
		" TO SPEED_UP PUSH UP_ARROW, "
		"TO SPEED_DOWN PUSH DOWN_ARROW(MIN 1 MAX 10)");
	wmove(info_win->info, 7, 1);
	wprintw(info_win->info,
		"                 PRESS 'x' TO GO TO JUMP TO THE END");
	wattroff(info_win->info, COLOR_PAIR(B_INFO) | A_BOLD);
}

/*
**TODO: Скорее всего vm_get_wins(vm) можно сделать один раз, записать жто в
** переменную и передавать именно ее значение, и не вызывать расчет много-много
** раз
*/
