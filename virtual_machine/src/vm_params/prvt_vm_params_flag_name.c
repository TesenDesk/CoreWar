/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_vm_params_flag_name.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 18:31:11 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/02 18:31:12 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_vm_params.h"

int				prvt_vm_params_flag_name(t_vm_params *self, char *param)
{
	long long num;

	num = ft_atol(param);
	if (!(ft_arg_is_num(param)))
		raise(__FILE__, __LINE__, ENOARGVAL);
	prvt_vm_params_set_player_name(self, num);
	return (FLAG_NUM_CODE);
}
