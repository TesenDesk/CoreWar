/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_add_new_carriage_node.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 16:54:43 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/13 16:54:43 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_vm.h"

void		vm_add_new_carriage_node(t_list *new_node)
{
	t_vm	*vm;

	vm = vm_singleton(VM_INSTANTIATE, 0, NULL);
	ft_lstadd(&(vm->carriage_head), new_node);
}
