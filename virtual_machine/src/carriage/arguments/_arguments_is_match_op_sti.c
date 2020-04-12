/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _arguments_is_match_op_sti.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 00:58:34 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/13 00:58:45 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_arguments.h"

int				_arguments_is_match_op_sti(t_arguments *self)
{
	int			conclusion;

	conclusion = self->types == OP_STI &&
		(self->op_code == REG_DIR_DIR || self->op_code == REG_REG_DIR);
	return (conclusion);
}
