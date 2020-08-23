/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_basic_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:46:53 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/08 16:38:08 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_visual.h"

void			draw_basic_info(t_vm *vm)
{
	t_wins      *info_win;

	info_win = vm_get_wins(vm);
	wattron(vm->wins->info, COLOR_PAIR(B_INFO) | A_BOLD);
	wmove(vm->wins->info, 1, 1);
	wprintw(vm->wins->info, " CYCLES_TO_DIE:   %zu\n",
		vm_get_cycles_to_die(vm));
	wmove(vm->wins->info, 2, 1);
	wprintw(vm->wins->info, " CURRENT_COUNTER: %zu\n",
		vm_get_cycles_counter(vm));
	wmove(vm->wins->info, 3, 1);
	wprintw(vm->wins->info, " GLOBAL_COUNTER:  %d\n",
		vm_get_global_counter(vm));
	wmove(vm->wins->info, 4, 1);
	wprintw(vm->wins->info, " CYCLES_DELTA:    %d\n", CYCLE_DELTA);
	wmove(vm->wins->info, 5, 1);
	wprintw(vm->wins->info, " GAME_SPEED:      %d\n", vm_get_speed(vm));
	wmove(vm->wins->info, 6, 1);
	wprintw(vm->wins->info,
		" TO SPEED_UP PUSH UP_ARROW, "
		"TO SPEED_DOWN PUSH DOWN_ARROW(MIN 1 MAX 10)");
	wmove(vm->wins->info, 7, 1);
	wprintw(vm->wins->info,
		"                 PRESS 'x' TO GO TO JUMP TO THE END");
	wattroff(vm->wins->info, COLOR_PAIR(B_INFO) | A_BOLD);
}
// TODO: Скорее всего vm_get_wins(vm) можно сделать один раз, записать жто в переменную и передавать именно ее значение, и не вызывать расчет много-много раз