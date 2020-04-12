/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _arguments_is_match_op_load_i.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 00:59:05 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/13 00:59:17 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_arguments.h"

int				_arguments_is_match_op_load_i(t_arguments *self)
{
	int			conclusion;

	conclusion = (self->op_code == OP_LDI || self->op_code == OP_LLDI) &&
		_arguments_not_nil_dir_or_reg_reg(self);
	return (conclusion);
}
