/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_xtor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:03:13 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/03 23:21:49 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm.h"

static t_vm		*_vm_ctor(int argc, char **argv)
{
	t_vm		*self;

	if ((self = (t_vm *)ft_memalloc(sizeof(*self))) == NULL)
		errors(__FILE__, __LINE__, ENOMEMORY);
	self->params = vm_params_ctor(argc, argv);
	self->arena = arena_ctor(self->params);
	self->carriage_head = vm_carriage_list_construct(self->arena);
	return (self);
}

static void		_vm_dtor(t_vm **self)
{
	if((*self)->params != NULL)
	{
		vm_params_dtor(&(*self)->params);
		if ((*self)->arena != NULL)
		{
			vm_arena_dtor(&(*self)->arena);
			if((*self)->carriage_head != NULL)
				vm_carriage_list_destruct(&(*self)->arena);
		}
	}
	ft_memdel((void **)self);
	return ;
}

t_vm			*vm_singleton(int instantiation_status, int argc, char **argv)
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
