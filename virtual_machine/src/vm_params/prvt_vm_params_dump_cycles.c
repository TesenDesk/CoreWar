/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_vm_params_dump_cycles.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 16:30:48 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/26 16:07:28 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_vm_params.h"

int				prvt_vm_params_dump_cycles(t_vm_params *self, char *param)
{
	long long	num;

	num = ft_atol(param);
	if (!(ft_arg_is_num(param)) || num < 0)
		ft_raise(__FILE__, __LINE__, ENOARGVAL);
	self->dump_cycles = num;
	self->is_set_dump = TRUE;
	return (FLAG_NUM_CODE);
}
