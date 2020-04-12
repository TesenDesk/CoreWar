/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _arguments_is_match_op_affect.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 00:55:06 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/13 00:55:21 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_arguments.h"

int				_arguments_is_match_op_affect(t_arguments *self)
{
	int			conclusion;

	conclusion = self->op_code == OP_AFF && self->types == REG_NIL_NIL;
	return (conclusion);
}
