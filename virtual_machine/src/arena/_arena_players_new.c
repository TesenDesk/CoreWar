/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _arena_players_new.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 23:01:59 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/09 00:03:41 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_arena.h"

t_player			**_arena_players_new(t_vm_params *params)
{
	t_player		**new_array;

	if((new_array = (t_player **)ft_memalloc(sizeof(*new_array))) == NULL)
		raise(__FILE__, __LINE__, ENOMEMORY);
	return (new_array);
}
