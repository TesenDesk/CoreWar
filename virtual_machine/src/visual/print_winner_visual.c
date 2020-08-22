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
	werase(vm_get_wins(vm)->win);

//	WARN // OLD CODE // DELETE IT // IF NEW CODE WORKS //
//	wattron(vm->wins->win, COLOR_PAIR(P_1_HOME + vm->arena->players[
//		vm->arena->last_live_player - 1]->name - 1) | A_BOLD);

	wattron(vm_get_wins(vm)->win, COLOR_PAIR(P_1_HOME +
		player_get_name(arena_get_player(vm_get_arena(vm),
		arena_get_last_live_player(vm_get_arena(vm)) - 1)) - 1) | A_BOLD);
	wmove(vm_get_wins(vm)->win, 1, 1);

//	WARN // OLD CODE // DELETE IT // IF NEW CODE WORKS //
//	wprintw(vm->wins->win, "%-20s(PLAYER #%d) WON!\n",
//		vm->arena->players[vm->arena->last_live_player - 1]->text_name,
//		vm->arena->players[vm->arena->last_live_player - 1]->name);

	wprintw(vm_get_wins(vm)->win, "%-20s(PLAYER #%d) WON!\n",
			player_get_text_name(arena_get_player(vm_get_arena(vm),
				arena_get_last_live_player(vm_get_arena(vm)) - 1)),
			player_get_name(arena_get_player(vm_get_arena(vm),
				arena_get_last_live_player(vm_get_arena(vm)) - 1)));

//	WARN // OLD CODE // DELETE IT // IF NEW CODE WORKS //
//	wattroff(vm->wins->win, COLOR_PAIR(P_1_HOME + vm->arena->players[
//		vm->arena->last_live_player - 1]->name - 1) | A_BOLD);

	wattroff(vm_get_wins(vm)->win, COLOR_PAIR(P_1_HOME +
		player_get_name(arena_get_player(vm_get_arena(vm),
			arena_get_last_live_player(vm_get_arena(vm)) - 1)) - 1) | A_BOLD);

	//END OF CODE UPDATE//

	wattron(vm_get_wins(vm)->win, COLOR_PAIR(B_INFO));
	wmove(vm_get_wins(vm)->win, 2, 1);
	wprintw(vm_get_wins(vm)->win, "       PRESS_ANY_KEY_TO_EXIT\n");
	wattroff(vm_get_wins(vm)->win, COLOR_PAIR(B_INFO) | A_BOLD);
	box(vm_get_wins(vm)->win, 0, 0);
	wrefresh(vm_get_wins(vm)->win);
	nodelay(stdscr, FALSE);
	getch();
}
