/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _arguments_op_code_is_affect.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 22:22:45 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/14 22:31:49 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_types.h"

int				_arguments_op_code_is_affect(t_arguments *self)
{
	int			conclusion;

	conclusion = self->op_code == OP_AFF;
	return (conclusion);
}
