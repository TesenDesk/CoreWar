/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _vm_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 22:40:44 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 22:48:48 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm.h"

t_vm		*_vm_new(int argc, char *argv[])
{
	t_vm		*self;

	if ((self = (t_vm *)ft_memalloc(sizeof(*self))) == NULL)
		raise(__FILE__, __LINE__, ENOMEMORY);
	self->params = vm_params_new(argc, argv);
	self->arena = arena_new(&self->params);
	self->carriage_head = vm_carriage_list_constructed_new(self->arena);
	return (self);
}
