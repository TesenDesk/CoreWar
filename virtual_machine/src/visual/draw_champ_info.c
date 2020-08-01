/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_champ_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:48:16 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/01 13:21:15 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_visual.h"

void		draw_champ_info(t_vm *vm)
{
	int		i;

	i = 0;
	while (i < (unsigned int)vm->arena->nb_players)
	{
		wattron(vm->wins->champ, COLOR_PAIR(P_1_HOME + i) | A_BOLD);
		wmove(vm->wins->champ, i * 3 + 1, 1);
		wprintw(vm->wins->champ, "P_%d_name: %40s", i + 1,
			vm->arena->players[i]->text_name);
		wmove(vm->wins->champ, i * 3 + 2, 1);
		wprintw(vm->wins->champ, "P_%d_comment: %37s", i + 1,
			vm->arena->players[i]->text_comment);
		wmove(vm->wins->champ, i * 3 + 3, 1);
		wprintw(vm->wins->champ, "carriage_num: %36d",
			vm->arena->carriage_num[i]);
		wattroff(vm->wins->champ, COLOR_PAIR(P_1_HOME + i) | A_BOLD);
		++i;
	}
}
