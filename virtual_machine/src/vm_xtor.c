/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_xtor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:03:13 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/03 19:11:34 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_private.h"

static t_vm		*_vm_ctor(int argc, char **argv)
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

static void		_vm_dtor(t_vm **self)
{

	return ;
}

t_vm				*vm_singleton(int instantiation_status,
						int argc, char **argv)
{
	static t_vm		*vm;

	if (instantiation_status == VM_INSTANTIATE)
	{
		if (!vm)
			vm = _vm_ctor(argc, argv);
	}
	else if (instantiation_status == VM_DESTRUCT)
	{
		if (vm)
			_vm_dtor(&vm);
	}
	return (vm);
}
