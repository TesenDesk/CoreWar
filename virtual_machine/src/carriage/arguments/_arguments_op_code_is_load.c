/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _arguments_op_code_is_load.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 22:23:52 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/14 22:31:54 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_types.h"

int				_arguments_op_code_is_load(t_arguments *self)
{
	int			conclusion;

	conclusion = (self->op_code == OP_LD || self->op_code == OP_LLD);
	return (conclusion);
}
