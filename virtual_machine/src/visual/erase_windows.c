/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_windows.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:50:13 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/01 13:23:05 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_visual.h"

void		erase_windows(t_vm *vm)
{
	int		i;

	i = 0;
	werase(vm->wins->arena);
	werase(vm->wins->info);
	werase(vm->wins->champ);
	while (i < MEM_SIZE)
	{
		vm->arena->colormap[i].player_index = 0;
		vm->arena->colormap[i].store_index = 0;
		++i;
	}
	i = 0;
	while (i < 4)
		vm->arena->carriage_num[i++] = 0;
}
