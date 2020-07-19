/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_arena_players_new.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 18:58:21 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/04 18:58:44 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_arena.h"

t_player			**prvt_arena_players_new(int num_players)
{
	t_player		**new_array;

	if ((new_array = (t_player **)ft_memalloc(sizeof(*new_array)
			* num_players)) == NULL)
		ft_raise(__FILE__, __LINE__, ENOMEMORY);
	return (new_array);
}
