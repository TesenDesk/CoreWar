/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _vm_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 22:41:52 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 22:49:08 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm.h"

void		_vm_destroy(t_vm **self)
{
	if((*self)->params != NULL)
		vm_params_destroy(&(*self)->params);
	if ((*self)->arena != NULL)
		vm_arena_destroy(&(*self)->arena);
	if((*self)->carriage_head != NULL)
		vm_carriage_list_destruct(&(*self)->arena);
	ft_memdel((void **)self);
	return ;
}
