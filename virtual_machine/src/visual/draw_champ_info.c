/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_champ_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:48:16 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/23 15:48:45 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_visual.h"

void		draw_champ_info(t_vm *vm)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < (unsigned int)arena_get_nb_players(vm_get_arena(vm)))
	{
		t_wins *wins;

		wins = vm_get_wins(vm);
		wattron(wins->champ, COLOR_PAIR(P_1_HOME + i) | A_BOLD);
		wmove(wins->champ, i * 3 + 1, 1);
		wprintw(wins->champ, "P_%d_name: %40s", i + 1,
			(tmp = player_get_text_name(arena_get_player(vm_get_arena(vm), i))));
		ft_memdel((void **)&tmp);
		wmove(wins->champ, i * 3 + 2, 1);
		wprintw(wins->champ, "P_%d_comment: %37s", i + 1,
			player_get_text_comment(arena_get_player(vm_get_arena(vm), i)));
		ft_memdel((void **)&tmp);
		wmove(wins->champ, i * 3 + 3, 1);
		wprintw(wins->champ, "carriage_num: %36d",
			arena_get_carriage_num(vm_get_arena(vm), i));
		wattroff(wins->champ, COLOR_PAIR(P_1_HOME + i) | A_BOLD);
		++i;
	}
}
