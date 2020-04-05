/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _vm_params_set_is_dump.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 01:12:10 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/06 01:12:35 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm_params.h"

void					_vm_params_set_is_dump(t_vm_params *self, char *useless)
{
	self->is_set_dump = TRUE;
	(void)useless;
	return;
}
