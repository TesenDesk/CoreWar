/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_windows.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:50:13 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/08 17:15:19 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_visual.h"

void		erase_windows(t_vm *vm)
{
	int		i;

	i = 0;
	werase(vm_get_wins(vm)->arena);
	werase(vm_get_wins(vm)->info);
	werase(vm_get_wins(vm)->champ);
	werase(vm_get_wins(vm)->hearts);
	while (i < MEM_SIZE)
	{
		arena_set_player_index(vm_get_arena(vm), i, 0);
		arena_set_store_index(vm_get_arena(vm), i, 0);
		++i;
	}
	i = 0;
	while (i < 4)
		arena_set_carriage_num(vm_get_arena(vm), i++, 0);
}
