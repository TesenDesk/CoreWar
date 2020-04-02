/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_xtor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:03:13 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/02 18:27:46 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_private.h"

t_vm			*vm_ctor(int argc, char **argv)
{
	t_vm		*self;

	if ((self = (t_vm *)ft_memalloc(sizeof(*self))) == NULL)
	{
		ft_putendl_fd("Could not allocate vm.", STDERR);
		exit(FAILURE);
	}
	self->errors = errors_ctor(&self);
	self->params = vm_params_ctor(argc, argv);
	self->arena = arena_ctor(self->params);
	self->carriage_head = vm_carriage_list_construct(self->arena);

	return (self);
}

void			vm_dtor(t_vm **self)
{

	return ;
}
