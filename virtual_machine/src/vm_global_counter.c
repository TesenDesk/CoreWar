/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_global_counter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 16:54:01 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/13 16:54:25 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_vm.h"

int			vm_global_counter(void)
{
	t_vm	*vm;

	vm = vm_singleton(VM_INSTANTIATE, 0, NULL);
	return (vm->global_counter);
}
