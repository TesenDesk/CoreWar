/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_singleton.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:03:13 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/09 00:10:11 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm.h"

t_vm			*vm_singleton(int instantiation_status, int argc, char *argv[])
{
	static t_vm		*vm;

	if (instantiation_status == VM_INSTANTIATE)
	{
		if (vm == NULL)
			vm = _vm_new(argc, argv);
	}
	else if (instantiation_status == VM_DESTRUCT)
	{
		if (vm)
			_vm_destroy(&vm);
	}
	return (vm);
}
