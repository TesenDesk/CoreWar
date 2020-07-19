/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _vm_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita_toropov <nikita_toropov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 22:40:44 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/28 20:36:33 by nikita_toro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm.h"

t_vm		*_vm_new(int argc, char *argv[])
{
	t_vm		*self;

	if ((self = (t_vm *)ft_memalloc(sizeof(*self))) == NULL)
		ft_raise(__FILE__, __LINE__, ENOMEMORY);
	self->params = vm_params_new(argc, argv);
	self->cycles_to_dump = vm_params_dump_cycles(self->params);
	self->verbosity_lvl = vm_params_verbosity_lvl(self->params);
	self->arena = arena_new(self->params);
	self->carriage_head = arena_carriage_list_new(self->arena);
	self->num_of_carriages = arena_nb_players(self->arena);
	self->speed = 1;
	return (self);
}