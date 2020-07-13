/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_vm_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 16:57:20 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/13 16:57:57 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_vm.h"

void		prvt_vm_destroy(t_vm **self)
{
	if ((*self)->params != NULL)
		vm_params_destroy(&(*self)->params);
	if ((*self)->arena != NULL)
		arena_destroy(&(*self)->arena);
	if ((*self)->carriage_head != NULL)
		vm_carriage_list_destruct(&(*self)->carriage_head);
	ft_memdel((void **)self);
	return ;
}
