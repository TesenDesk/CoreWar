/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_dispatched.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:39:51 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/13 18:02:35 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

void		operation_dispatched(t_carriage *self)
{
	t_op op;

	op = g_op[self->op_code - 1];
	op.operation(self);
}
