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
	if (self->op_code >= OP_LIVE && self->op_code <= OP_AFF)
		self->is_correct_op_code = TRUE;
	else
		self->is_correct_op_code = FALSE;
	return ;
}
