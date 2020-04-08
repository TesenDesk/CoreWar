/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vmp_params_dtor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 21:50:06 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 21:53:14 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm_params.h"

void					vm_params_dtor(t_vm_params **self)
{
	_vm_params_destroy_players_lists(*self);
	ft_memdel((void **)self);
	return;
}
