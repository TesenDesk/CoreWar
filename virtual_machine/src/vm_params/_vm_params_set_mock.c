/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _vm_params_set_mock.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 01:15:38 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/06 21:51:07 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm_params.h"

void					_vm_params_set_mock(t_vm_params *never_passed,
							char *useless)
{
	if (TRUE)
		raise(__FILE__, __LINE__, EMOCKMETHOD);
	(void)never_passed;
	(void)useless;
	return;
}
