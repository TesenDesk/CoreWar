/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_vm_params_flag_verbose.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 16:21:43 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/04 16:22:00 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_vm_params.h"

int				prvt_vm_params_flag_verbose(t_vm_params *self, char *param)
{
	long long	num;

	num = ft_atol(param);
	if (!(ft_arg_is_num(param)))
		raise(__FILE__, __LINE__, ENOARGVAL);
	self->verbosity_lvl = num;
	return (FLAG_NUM_CODE);
}
