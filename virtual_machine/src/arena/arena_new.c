/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:29:47 by yurezz            #+#    #+#             */
/*   Updated: 2020/07/04 18:54:41 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_arena.h"

static void			prvt_arena_new_precondition_check(void)
{
	if (MEM_SIZE <= 0 || CHAMP_MAX_SIZE <= 0 || REG_NUMBER <= 0)
		raise(__FILE__, __LINE__, EINVALCONSTANTS);
	return ;
}

static void			arena_fill_in_the_data(t_arena *self)
{
	char			*arena_field;
	int				curr;
	int				step;

	step = MEM_SIZE / self->nb_players;
	curr = 0;
	if (!(arena_field = ft_memalloc(MEM_SIZE*2 * sizeof(char))))
		raise(__FILE__, __LINE__, EINVALCONSTANTS);
	while (curr < self->nb_players)
	{
		ft_memcpy((arena_field + (curr) * step),
		player_code(self->players[curr]),
		player_code_size(self->players[curr]));
		curr += 1;
	}
	self->data = arena_field;
//	printf("init:%p\n", self->data);
//	getchar();
	return ;
}

t_arena				*arena_new(t_vm_params *params)
{
	t_arena			*self;

	prvt_arena_new_precondition_check();
	if ((self = (t_arena *)ft_memalloc(sizeof(*self))) == NULL)
		raise(__FILE__, __LINE__, ENOMEMORY);
	self->nb_players = vm_params_nb_players(params);
	self->last_live_player = self->nb_players;
	self->players = prvt_arena_players_new(self->nb_players);
	vm_params_fill_and_sort_array_of_players(params, self);
	arena_fill_in_the_data(self);
	return (self);
}
