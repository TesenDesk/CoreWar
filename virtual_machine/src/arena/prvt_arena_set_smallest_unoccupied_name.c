/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_arena_set_smallest_unoccupied_name.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 18:59:19 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/04 19:00:13 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_arena.h"

static void		prvt_arena_set_smallest_unoccupied_name_postcondition_check(
					t_arena *self)
{
	if (self->smallest_unoccupied_name > self->nb_players)
		raise(__FILE__, __LINE__, EBADPLAYERNAME);
	return ;
}

void			prvt_arena_set_smallest_unoccupied_name(t_arena *self)
{
	int			new_player_name;

	new_player_name = self->smallest_unoccupied_name;
	while ((self->players)[new_player_name] != NULL
		&& new_player_name < self->nb_players)
		++new_player_name;
	self->smallest_unoccupied_name = new_player_name;
	prvt_arena_set_smallest_unoccupied_name_postcondition_check(self);
	return ;
}
