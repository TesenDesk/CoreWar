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
	char	*tmp;

	i = 0;
	while (i < (unsigned int)arena_get_nb_players(vm->arena))
	{
		wattron(vm->wins->champ, COLOR_PAIR(P_1_HOME + i) | A_BOLD);
		wmove(vm->wins->champ, i * 3 + 1, 1);
		wprintw(vm->wins->champ, "P_%d_name: %40s", i + 1,
			(tmp = player_get_text_name(arena_get_player(vm->arena, i))));
		ft_memdel((void **)&tmp);
		wmove(vm->wins->champ, i * 3 + 2, 1);
		wprintw(vm->wins->champ, "P_%d_comment: %37s", i + 1,
			player_get_text_comment(arena_get_player(vm->arena, i)));
		ft_memdel((void **)&tmp);
		wmove(vm->wins->champ, i * 3 + 3, 1);
		wprintw(vm->wins->champ, "carriage_num: %36d",
			arena_get_carriage_num(vm->arena, i));
		wattroff(vm->wins->champ, COLOR_PAIR(P_1_HOME + i) | A_BOLD);
		++i;
	}
}
