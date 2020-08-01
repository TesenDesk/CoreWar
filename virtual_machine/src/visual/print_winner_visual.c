/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_winner_visual.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:36:49 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/01 13:14:08 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_visual.h"

void	print_winner_visual(t_vm *vm) //TODO: Оптимизировать надо ли нам? Одинаковых вызовов многовато, однако.
{
	werase(vm->wins->win);

//	WARN // OLD CODE // DELETE IT // IF NEW CODE WORKS //
//	wattron(vm->wins->win, COLOR_PAIR(P_1_HOME + vm->arena->players[
//		vm->arena->last_live_player - 1]->name - 1) | A_BOLD);

	wattron(vm->wins->win, COLOR_PAIR(P_1_HOME + arena_get_player(vm->arena, arena_get_last_live_player(vm->arena) - 1)->name - 1) | A_BOLD);
	wmove(vm->wins->win, 1, 1);

//	WARN // OLD CODE // DELETE IT // IF NEW CODE WORKS //
//	wprintw(vm->wins->win, "%-20s(PLAYER #%d) WON!\n",
//		vm->arena->players[vm->arena->last_live_player - 1]->text_name,
//		vm->arena->players[vm->arena->last_live_player - 1]->name);

	wprintw(vm->wins->win, "%-20s(PLAYER #%d) WON!\n",
			arena_get_player(vm->arena, arena_get_last_live_player(vm->arena) - 1)->text_name,
			arena_get_player(vm->arena, arena_get_last_live_player(vm->arena) - 1)->name);

//	WARN // OLD CODE // DELETE IT // IF NEW CODE WORKS //
//	wattroff(vm->wins->win, COLOR_PAIR(P_1_HOME + vm->arena->players[
//		vm->arena->last_live_player - 1]->name - 1) | A_BOLD);

	wattroff(vm->wins->win, COLOR_PAIR(P_1_HOME + arena_get_player(vm->arena, arena_get_last_live_player(vm->arena) - 1)->name - 1) | A_BOLD);

	//END OF CODE UPDATE//

	wattron(vm->wins->win, COLOR_PAIR(B_INFO));
	wmove(vm->wins->win, 2, 1);
	wprintw(vm->wins->win, "       PRESS_ANY_KEY_TO_EXIT\n");
	wattroff(vm->wins->win, COLOR_PAIR(B_INFO) | A_BOLD);
	box(vm->wins->win, 0, 0);
	wrefresh(vm->wins->win);
	nodelay(stdscr, FALSE);
}
