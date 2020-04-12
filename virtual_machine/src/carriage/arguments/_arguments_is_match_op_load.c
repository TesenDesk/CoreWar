/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _arguments_is_match_op_load.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 00:56:37 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/13 00:56:55 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_arguments.h"

int				_arguments_is_match_op_load(t_arguments *self)
{
	int			conclusion;

	conclusion = (self->op_code == OP_LD || self->op_code == OP_LLD) && 
		(self->types == DIR_REG_NIL || self->types == IND_REG_NIL);
	return (conclusion);
}
