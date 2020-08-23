/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_winner_visual.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:36:49 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/08 17:20:06 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_visual.h"

void	print_winner_visual(t_vm *vm) //TODO: Оптимизировать надо ли нам? Одинаковых вызовов многовато, однако.
{
	werase(vm->wins->win);
	wattron(vm->wins->win, COLOR_PAIR(P_1_HOME +
		player_get_name(arena_get_player(vm->arena,
		arena_get_last_live_player(vm->arena) - 1)) - 1) | A_BOLD);
	wmove(vm->wins->win, 1, 1);
	wprintw(vm->wins->win, "%-20s(PLAYER #%d) WON!\n",
			player_get_text_name(arena_get_player(vm->arena,
				arena_get_last_live_player(vm->arena) - 1)),
			player_get_name(arena_get_player(vm->arena,
				arena_get_last_live_player(vm->arena) - 1)));
	wattroff(vm->wins->win, COLOR_PAIR(P_1_HOME +
		player_get_name(arena_get_player(vm->arena,
			arena_get_last_live_player(vm->arena) - 1)) - 1) | A_BOLD);
	wattron(vm->wins->win, COLOR_PAIR(B_INFO));
	wmove(vm->wins->win, 2, 1);
	wprintw(vm->wins->win, "       PRESS_ANY_KEY_TO_EXIT\n");
	wattroff(vm->wins->win, COLOR_PAIR(B_INFO) | A_BOLD);
	box(vm->wins->win, 0, 0);
	wrefresh(vm->wins->win);
	nodelay(stdscr, FALSE);
	getch();
}
