/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_carriage_set_cycles_to_perform_op.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 20:39:37 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/04 21:08:12 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_carriage.h"

void		prvt_carriage_set_cycles_to_perform_op(t_carriage *self) {
	t_op op;

	if (self->is_correct_op_code)
	{
		op = g_op[self->op_code - 1];
		self->cycles_to_perform_op = op.cycles_to_perform;
	}
}
