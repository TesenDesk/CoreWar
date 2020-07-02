/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_params_dump_cycles.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 19:03:01 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/02 19:03:02 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm_params.h"

int			vm_params_dump_cycles(t_vm_params *self)
{
	if (self->is_set_dump == TRUE)
		return (self->dump_cycles);
	return (-1);
}
