/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_set_urgent_break.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 17:37:47 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/08 17:38:17 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_vm.h"

void			vm_set_urgent_break(t_vm *self, int urgent_break)
{
	self->urgent_break = urgent_break;
	return ;
}
