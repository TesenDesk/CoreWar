/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_xtor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:29:47 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/07 14:05:44 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_arena.h"

t_player			**arena_players_new(t_vm_params *params)
{
	t_player		**new_array;

	if((new_array = (t_player **)ft_memalloc(sizeof(*new_array))) == NULL)
		raise(__FILE__, __LINE__, ENOMEMORY);
	return (new_array);
}

static void			_arena_ctor_precondition_check(void)
{
	if (MEM_SIZE <= 0 || CHAMP_MAX_SIZE <= 0 || REG_NUMBER <= 0)
		raise(__FILE__, __LINE__, EINVALCONSTANTS);
	return;
}

t_arena				*arena_ctor(t_vm_params *params)
{
	t_arena			*new;

	_arena_ctor_precondition_check();
	if ((new = (t_arena *)ft_memalloc(sizeof(*new))) == NULL)
		raise(__FILE__, __LINE__, ENOMEMORY);
	new->nb_players = vm_params_nb_players(params);
	new->players = arena_players_new(new->nb_players);
	vm_params_named_sorted_array_of_players(params);
	vm_params_destroy_players(params);
	return (new);
}

void				arena_dtor(t_arena **self)
{
	player_dtor(&(*self)->players);
	ft_memdel((void **)self);
	return;
}
