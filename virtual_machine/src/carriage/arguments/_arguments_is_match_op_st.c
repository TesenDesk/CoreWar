/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _arguments_is_match_op_st.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 00:57:55 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/13 00:58:06 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_arguments.h"

int				_arguments_is_match_op_st(t_arguments *self)
{
	int			conclusion;

	conclusion = self->op_code == OP_ST &&
		(self->types == REG_IND_NIL || self->types == REG_REG_NIL);
	return (conclusion);
}
