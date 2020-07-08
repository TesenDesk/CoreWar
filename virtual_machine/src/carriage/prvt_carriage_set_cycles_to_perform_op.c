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

void		prvt_carriage_set_cycles_to_perform_op(t_carriage *self)
{
	static int		cycles_to_perform[] =
	{0, 10, 5, 5, 10, 10, 6, 6, 6, 20, 25, 25, 800, 10, 50, 1000, 2};

	if (self->is_correct_op_code)
		self->cycles_to_perform_op = cycles_to_perform[self->op_code];
}
