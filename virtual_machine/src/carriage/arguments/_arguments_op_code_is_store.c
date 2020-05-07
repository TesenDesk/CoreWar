/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _argumtnts_op_code_is_store.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 22:24:51 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/14 22:25:03 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_types.h"

int				_argumtnts_op_code_is_store(t_arguments *self)
{
	int			conclusion;

	conclusion = self->op_code == OP_ST;
	return (conclusion);
}
