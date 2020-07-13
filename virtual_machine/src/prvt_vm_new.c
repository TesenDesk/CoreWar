/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_vm_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 16:56:47 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/13 16:56:47 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_vm.h"

t_vm		*prvt_vm_new(int argc, char **argv)
{
	t_vm		*self;

	if ((self = (t_vm *)ft_memalloc(sizeof(*self))) == NULL)
		raise(__FILE__, __LINE__, ENOMEMORY);
	self->params = vm_params_new(argc, argv);
	self->cycles_to_dump = vm_params_dump_cycles(self->params);
	self->verbosity_lvl = vm_params_verbosity_lvl(self->params);
	self->arena = arena_new(self->params);
	self->carriage_head = arena_carriage_list_new(self->arena);
	self->num_of_carriages = arena_nb_players(self->arena);
	return (self);
}
