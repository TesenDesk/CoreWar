/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_verbosity_lvl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 16:57:04 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/13 16:57:04 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_vm.h"

int			vm_verbosity_lvl(void)
{
	t_vm	*vm;

	vm = vm_singleton(VM_INSTANTIATE, 0, NULL);
	return (vm->verbosity_lvl);
}
