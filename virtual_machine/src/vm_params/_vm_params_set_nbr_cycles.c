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
<<<<<<< HEAD
	self->nb_cycles = ft_atol(nbr_cycles_str);
=======
	self->nb_cycles = ft_atol(nbr_sycles_str);
>>>>>>> e3e25fe0ac3684476028641a79df83acff7a3173
	return;
}
