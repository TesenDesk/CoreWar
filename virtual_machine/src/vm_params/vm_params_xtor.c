/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_params_xtor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:27:54 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/03 23:58:52 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm_params.h"

t_vm_params			*vm_params_xtor(int argc, char *argv[])
{
	t_vm_params		*self;
	char			**params;

	if (argc < 2)
		errors(__FILE__, __LINE__, EINVALARG);
	params = argv;
	while (TRUE)
		(*vm_params_states(self.state))(self, params);
	return (self);
}