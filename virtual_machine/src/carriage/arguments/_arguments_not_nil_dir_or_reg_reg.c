/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _arguments_not_nil_dir_or_reg_reg.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 00:53:10 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/13 00:53:32 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_arguments.h"

int				_arguments_not_nil_dir_or_reg_reg(t_arguments *self)
{
	int			conclusion;
	int			is_not_nil_arg_1;
	int			is_not_nil_arg_2;
	int			is_not_nil_arg_3;

	is_not_nil_arg_1 = self->types & IND_NIL_NIL;
	is_not_nil_arg_2 = self->types & NIL_DIR_NIL || self->types & NIL_REG_NIL;
	is_not_nil_arg_3 = self->types & NIL_NIL_REG;
	return (conclusion);
}
