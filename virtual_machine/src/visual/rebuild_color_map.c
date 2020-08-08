/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rebuild_color_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:45:21 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/08 18:48:54 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_visual.h"

/*
**		while (index < 4)
**		{
**			arena->colormap[
**				(((t_carriage *) iter->content)->stor_pos +
**				index) % MEM_SIZE].cell_index =
**				((t_carriage *) iter->content)->player_name;
**			arena->colormap[
**				(((t_carriage *) iter->content)->stor_pos +
**				 index) % MEM_SIZE].store_index = 1;
**			++index;
**		}
**		index = 0;
*/

// static void	rebuild_color_map_util(t_arena *arena, t_list *iter, int *index)
// {
// 	while (index < 4)
// 	{
// 		arena->colormap[(((t_carriage *)iter->content)->stor_pos + index) %
// 			MEM_SIZE].cell_index = ((t_carriage *)iter->content)->player_name;
// 		arena->colormap[(((t_carriage *)iter->content)->stor_pos + index) %
// 			MEM_SIZE].store_index = 1;
// 		++(*index);
// 	}
// }

void		rebuild_color_map(t_arena *arena, t_vm *vm)
{
	t_list	*iter;
	int		index;

	index = 0;
	iter = vm->carriage_head;
	while (iter != NULL)
	{
//		arena->colormap[((t_carriage*)iter->content)->arena_position %
//			MEM_SIZE].player_index = ((t_carriage*)iter->content)->player_name; //TODO: old code, delete it
		arena_set_player_index(arena, ((t_carriage*)iter->content)->arena_position % MEM_SIZE, ((t_carriage*)iter->content)->player_name);
//		arena->carriage_num[((t_carriage *)iter->content)->player_name - 1] +=
//			1; //TODO: old code, delete it
		// WARN!!!!!!!! BAD CODE AHEAD! TODO: NEED TO FIX IT //
		arena_set_carriage_num(arena, ((t_carriage *)iter->content)->player_name - 1, arena_get_carriage_num(arena, ((t_carriage *)iter->content)->player_name - 1) +1);

		if (((t_carriage *)iter->content)->was_store == TRUE)
		{
			while (index < 4)
			{
				// rebuild_color_map_util(arena, iter, &index); // <- not my comment. it was here before

//				arena->colormap[
//					(((t_carriage *) iter->content)->stor_pos +
//					index) % MEM_SIZE].cell_index =
//					((t_carriage *) iter->content)->player_name;
//				arena->colormap[
//					(((t_carriage *) iter->content)->stor_pos +
//					 index) % MEM_SIZE].store_index = 1; //TODO: old code, delete it

				arena_set_cell_index(arena, (((t_carriage *) iter->content)->stor_pos + index) % MEM_SIZE, ((t_carriage *) iter->content)->player_name);
				arena_set_store_index(arena, (((t_carriage *) iter->content)->stor_pos + index) % MEM_SIZE, 1);

				++index;
			}
			index = 0;
		}
		iter = iter->next;
	}
}
// TODO: Это метод очевидно класса vm. Нужно его туда перенести. 
// TODO: Нужно вставить геттеры и сеттеры, они готовы, но код слишком запутанный, не могу вставит без ошибок
