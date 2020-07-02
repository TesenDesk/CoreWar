/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_params_verbosity_lvl.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 18:40:50 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/02 18:40:50 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm_params.h"

int		vm_params_verbosity_lvl(t_vm_params *self)
{
	return (self->verbosity_lvl);
}
