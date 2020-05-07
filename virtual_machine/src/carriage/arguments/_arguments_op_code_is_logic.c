/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _arguments_op_code_is_logic.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 22:25:55 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/14 22:31:56 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_arguments.h"

int				_arguments_op_code_is_logic(t_arguments *self)
{
	int			conclusion;

	conclusion = (self->op_code == OP_AND ||
		self->op_code == OP_OR || self->op_code == OP_XOR);
	return (conclusion);
}
