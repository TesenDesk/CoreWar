/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _arguments_op_code_is_arithmetic.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 22:23:18 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/14 22:31:50 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_arguments.h"

int				_arguments_op_code_is_arithmetic(t_arguments *self)
{
	int			conclusion;

	conclusion = (self->op_code == OP_ADD || self->op_code == OP_SUB);
	return (conclusion);
}
