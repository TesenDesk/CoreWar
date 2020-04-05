/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_params_xtor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:27:54 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/06 01:18:17 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm_params.h"

t_vm_params				*vm_params_xtor(int argc, char *argv[])
{
	t_vm_params			*self;

	if (argc < 2)
		raise(__FILE__, __LINE__, EINVALARG);
	_vm_params_parse(self, argv);
	return (self);
}
