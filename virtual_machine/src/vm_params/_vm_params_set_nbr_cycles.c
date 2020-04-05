/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _vm_params_set_nbr_cycles.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 01:05:02 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/06 01:11:45 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm_params.h"

void					_vm_params_set_nbr_cycles(t_vm_params *self,
							char *nbr_sycles_str)
{
	if (ft_strint_ou_flow(*nbr_sycles_str, self->nb_cycles) == FAILURE)
		raise(__FILE__, __LINE__, EINTOUFLOW);
	self->is_set_dump == TRUE;
	return;
}
