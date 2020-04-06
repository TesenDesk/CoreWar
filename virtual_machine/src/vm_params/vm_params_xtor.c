/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_params_xtor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:27:54 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/06 22:16:24 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm_params.h"

static void				_vm_params_precondition_check(int argc)
{
	if (argc < 2)
		raise(__FILE__, __LINE__, EINVALARG);
	return;
}

static void				_vm_params_postcondition_check(t_vm_params *self)
{
	if (self->nb_players <= 0)
		raise(__FILE__, __LINE__, ENOPLAYERS);
	return;
}

t_vm_params				*vm_params_ctor(int argc, char *argv[])
{
	t_vm_params			*self;

	_vm_params_precondition_check(argc);
	if ((self = (t_vm_params *)ft_memalloc(sizeof(*self))) == NULL)
		raise(__FILE__, __LINE__, ENOMEMORY);
	_vm_params_parse(self, argv);
	_vm_params_postcondition_check(self);
	return (self);
}

static void				_vm_params_destroy_player(void *_player, size_t mock)
{
	t_vmp_player		*player;

	player = (t_vmp_player *)_player;
	vmp_player_dtor(&player);
	(void)mock;
	return;
}

void					vm_params_dtor(t_vm_params **self)
{
	ft_lstdel(&(*self)->nb_players, _vm_params_destroy_player);
	ft_memdel((void **)self);
	return;
}