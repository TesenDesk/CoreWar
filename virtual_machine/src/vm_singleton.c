/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_singleton.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:03:13 by yurezz            #+#    #+#             */
/*   Updated: 2020/07/01 18:26:48 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_vm.h"

t_vm			*vm_singleton(int instantiation_status, int argc, char *argv[])
{
	static t_vm		*self;

	if (instantiation_status == VM_INSTANTIATE)
	{
		if (self == NULL)
			self = prvt_vm_new(argc, argv);
	}
	else if (instantiation_status == VM_DESTRUCT)
	{
		if (self != NULL)
			prvt_vm_destroy(&self);
	}
	return (self);
}
