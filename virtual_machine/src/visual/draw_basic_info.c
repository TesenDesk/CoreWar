/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_basic_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:46:53 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/08 15:56:08 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_visual.h"

void			draw_basic_info(t_vm *vm)
{
	wattron(vm_get_wins(vm)->info, COLOR_PAIR(B_INFO) | A_BOLD);
	wmove(vm_get_wins(vm)->info, 1, 1);
	wprintw(vm_get_wins(vm)->info, " CYCLES_TO_DIE:   %zu\n",
		(unsigned int)vm->cycles_to_die);
	wmove(vm_get_wins(vm)->info, 2, 1);
	wprintw(vm_get_wins(vm)->info, " CURRENT_COUNTER: %zu\n",
		(unsigned int)vm->cycles_counter);
	wmove(vm_get_wins(vm)->info, 3, 1);
	wprintw(vm_get_wins(vm)->info, " GLOBAL_COUNTER:  %d\n", vm->global_counter);
	wmove(vm_get_wins(vm)->info, 4, 1);
	wprintw(vm_get_wins(vm)->info, " CYCLES_DELTA:    %d\n", CYCLE_DELTA);
	wmove(vm_get_wins(vm)->info, 5, 1);
	wprintw(vm_get_wins(vm)->info, " GAME_SPEED:      %d\n", vm->speed);
	wmove(vm_get_wins(vm)->info, 6, 1);
	wprintw(vm_get_wins(vm)->info,
		" TO SPEED_UP PUSH UP_ARROW, "
		"TO SPEED_DOWN PUSH DOWN_ARROW(MIN 1 MAX 10)");
	wmove(vm_get_wins(vm)->info, 7, 1);
	wprintw(vm_get_wins(vm)->info,
		"                 PRESS 'x' TO GO TO JUMP TO THE END");
	wattroff(vm_get_wins(vm)->info, COLOR_PAIR(B_INFO) | A_BOLD);
}
// TODO: Скорее всего vm_get_wins(vm) можно сделать один раз, записать жто в переменную и передавать именно ее значение, и не вызывать расчет много-много раз