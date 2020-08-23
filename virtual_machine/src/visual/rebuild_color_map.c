/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rebuild_color_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:45:21 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/23 15:48:30 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_visual.h"

void		rebuild_color_map(t_arena *arena, t_vm *vm)
{
	t_list			*iter; //TODO: Norme error: func has 27 lines
	int				index;
	unsigned int	coord;

	index = 0;
	iter = vm->carriage_head;
	while (iter != NULL)
	{
		arena_set_player_index(arena,
				((t_carriage*)iter->content)->arena_position % MEM_SIZE,
				((t_carriage*)iter->content)->player_name);
		arena_change_carriage_num(arena,
				((t_carriage *)iter->content)->player_name - 1, 1);
		if (((t_carriage *)iter->content)->was_store == TRUE)
		{
			while (index < 4)
			{
				coord = (((t_carriage *)iter->content)->stor_pos);
				arena_set_cell_index(arena, (coord + index) % MEM_SIZE,
						((t_carriage *)iter->content)->player_name);
				arena_set_store_index(arena, (coord + index) % MEM_SIZE, 1);
				++index;
			}
			index = 0;
		}
		iter = iter->next;
	}
}

/*
**TODO: Это метод очевидно класса vm. Нужно его туда перенести.
**TODO: Нужно вставить геттеры и сеттеры, они готовы, но код слишком
** запутанный, не могу вставит без ошибок
*/
