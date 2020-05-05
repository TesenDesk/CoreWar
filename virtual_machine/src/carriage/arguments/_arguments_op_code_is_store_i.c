/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _arithmetic_op_code_is_store_i.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 22:25:24 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/14 22:25:34 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_types.h"

int				_arithmetic_op_code_is_store_i(t_arguments *self)
{
	int			conclusion;

	conclusion = self->types == OP_STI;
	return (conclusion);
}
