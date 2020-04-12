/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_singleton.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:03:13 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/12 13:34:00 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm.h"

t_vm			*vm_singleton(int instantiation_status, int argc, char *argv[])
{
	static t_vm		*self;

	if (instantiation_status == VM_INSTANTIATE)
	{
		if (self == NULL)
			self = _vm_new(argc, argv);
	}
	else if (instantiation_status == VM_DESTRUCT)
	{
		if (self != NULL)
			_vm_destroy(&self);
	}
	return (self);
}
