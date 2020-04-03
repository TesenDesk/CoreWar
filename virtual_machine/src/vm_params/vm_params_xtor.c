/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_params_xtor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:27:54 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/03 23:22:27 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm_params.h"

t_vm_params			*vm_params_xtor(int argc, char **argv)
{
	t_vm_params		*self;

	if (argc < 2)
		errors(__FILE__, __LINE__, EINVALARG);
	return (self);
}