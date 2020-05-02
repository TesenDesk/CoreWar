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
							char *nbr_cycles_str)
{
	if (ft_strint_ou_flow(*nbr_cycles_str, &(self->nb_cycles)) == FAILURE)
		raise(__FILE__, __LINE__, EINTOUFLOW);
	// self->is_set_dump = TRUE;
	return;
}
