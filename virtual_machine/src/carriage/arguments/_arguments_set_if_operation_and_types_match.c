/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _arguments_set_if_operation_and_types_match        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 01:00:06 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/14 22:12:07 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_arguments.h"


void					_arguments_set_if_op_code_and_types_match(
							t_arguments *self)
{
	static t_types		*dispatcher[] = 
	{
		types_do_match_op_life,
		types_do_match_op_affect,
		types_do_match_op_load,
		types_do_match_op_store,
		types_do_match_op_load_i,
		types_do_match_op_store_i,
		types_do_match_op_logic,
		types_do_match_op_arithmetic,
	};

	self->are_match_operation_and_argument_types =
		(*dispatcher[self->op_group])(self->types);
	return;
}
