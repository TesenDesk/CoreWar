/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_carriage_list_destruct.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 16:53:52 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/13 16:53:52 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_vm.h"

void		vm_carriage_list_destruct(t_list **carriage_list)
{
	ft_lstdel(carriage_list, carriage_destroy);
}
