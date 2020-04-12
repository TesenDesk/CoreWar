/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _arguments_is_match_op_life.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 00:54:19 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/13 00:54:32 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_arguments.h"

int				_arguments_is_match_op_life(t_arguments *self)
{
	int			conclusion;

	conclusion = self->types == NO_ARGTYPES ? TRUE : FALSE;
	return (conclusion);
}
