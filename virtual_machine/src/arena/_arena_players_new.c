/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _tt_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 23:01:59 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 23:03:05 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_arena.h"
/*
 * долэен быть инт
 */
t_player			**_arena_players_new(int	num_players)
{
	t_player		**new_array;

	if((new_array = (t_player **)ft_memalloc(sizeof(*new_array) * num_players)) == NULL)
		raise(__FILE__, __LINE__, ENOMEMORY);
	return (new_array);
}