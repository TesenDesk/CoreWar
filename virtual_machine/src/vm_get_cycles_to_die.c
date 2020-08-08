/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_get_cycles_to_die.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 15:59:37 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/08 16:35:17 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_vm.h"

unsigned int	vm_get_cycles_to_die(t_vm *self)
{
	return (self->cycles_to_die);
}
