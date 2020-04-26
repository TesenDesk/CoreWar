/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_params_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita_toropov <nikita_toropov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 21:50:06 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/26 21:42:36 by nikita_toro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm_params.h"

void					vm_params_destroy(t_vm_params **self)
{
	_vm_params_destroy_players_lists(*self);
	ft_memdel((void **)self);
	return;
}
