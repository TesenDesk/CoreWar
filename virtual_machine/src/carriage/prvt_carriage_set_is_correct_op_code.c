/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_carriage_set_is_correct_op_code.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 17:51:01 by yurezz            #+#    #+#             */
/*   Updated: 2020/07/04 21:02:48 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_carriage.h"

void		prvt_carriage_set_is_correct_op_code(t_carriage *self)
{
	if (self->op_code > OP_MOCK && self->op_code < NUMBER_OF_OPERATIONS)
		self->is_correct_op_code = 1;
	else
		self->is_correct_op_code = 0;
	return ;
}
