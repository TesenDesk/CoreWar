/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _arguments_set_if_operation_and_types_match        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 01:00:06 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/13 01:00:38 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_arguments.h"

void			_arguments_set_if_operation_and_types_match(t_arguments *self)
{
	if (
		_arguments_is_match_op_life(self) ||
		_arguments_is_match_op_affect(self) ||
		_arguments_is_match_op_arithmetic(self) ||
		_arguments_is_match_op_load(self) ||
		_arguments_is_match_op_st(self) ||
		_arguments_is_match_op_sti(self) ||
		_arguments_is_match_op_logic(self) ||
		_arguments_is_match_op_load_i(self))
		self->are_match_operation_and_argument_types = TRUE;
	else
		self->are_match_operation_and_argument_types = FALSE;
	return;
}
