/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_params_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 18:31:53 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/02 18:31:53 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_vm_params.h"

void					vm_params_destroy(t_vm_params **self)
{
	vm_params_destroy_players_lists(*self);
	ft_memdel((void **)self);
	return ;
}
