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

void	print_winner_visual(t_vm *vm)
{
	werase(vm->wins->win);
	wattron(vm->wins->win, COLOR_PAIR(P_1_HOME + vm->arena->players[
		vm->arena->last_live_player - 1]->name - 1) | A_BOLD);
	wmove(vm->wins->win, 1, 1);
	wprintw(vm->wins->win, "%-20s(PLAYER #%d) WON!\n",
		vm->arena->players[vm->arena->last_live_player - 1]->text_name,
		vm->arena->players[vm->arena->last_live_player - 1]->name);
	wattroff(vm->wins->win, COLOR_PAIR(P_1_HOME + vm->arena->players[
		vm->arena->last_live_player - 1]->name - 1) | A_BOLD);
	wattron(vm->wins->win, COLOR_PAIR(B_INFO));
	wmove(vm->wins->win, 2, 1);
	wprintw(vm->wins->win, "       PRESS_ANY_KEY_TO_EXIT\n");
	wattroff(vm->wins->win, COLOR_PAIR(B_INFO) | A_BOLD);
	box(vm->wins->win, 0, 0);
	wrefresh(vm->wins->win);
	nodelay(stdscr, FALSE);
}
