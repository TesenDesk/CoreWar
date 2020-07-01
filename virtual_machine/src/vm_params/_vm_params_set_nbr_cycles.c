/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _vm_params_set_nbr_cycles.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita_toropov <nikita_toropov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 01:05:02 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/26 20:24:05 by nikita_toro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm_params.h"

void					_vm_params_set_nbr_cycles(t_vm_params *self,
							char *nbr_sycles_str)
{
	self->nb_cycles = ft_atol(nbr_sycles_str);
	return;
}
