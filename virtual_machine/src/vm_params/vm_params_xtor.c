/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_params_xtor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:27:54 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/04 14:03:51 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm_params.h"

static void			_vm_params_parse(t_vm_params *self, char **params)
{
	int				curr_player_name;
	int				state;

	while ((state = vmp_state(*params)) != VMP_STOP)
		vmp_vtable(state, params);
	return ;
}

t_vm_params			*vm_params_xtor(int argc, char *argv[])
{
	t_vm_params		*self;

	if (argc < 2)
		errors(__FILE__, __LINE__, EINVALARG);
	_vm_params_parse(self, argv);
	return (self);
}