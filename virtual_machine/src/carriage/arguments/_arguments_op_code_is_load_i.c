/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _arguments_op_code_is_load_i.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 22:21:31 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/14 22:31:52 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_arguments.h"

int				_arguments_op_code_is_load_i(t_arguments *self)
{
	int			conclusion;

	conclusion = (self->op_code == OP_LDI || self->op_code == OP_LLDI);
	return (conclusion);
}
