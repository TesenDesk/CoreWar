/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _types_not_nil_dir_or_reg_reg.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 00:53:10 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/14 22:19:45 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_types.h"

int				_types_not_nil_dir_or_reg_reg(int self)
{
	int			conclusion;
	int			is_not_nil_arg_1;
	int			is_not_nil_arg_2;
	int			is_not_nil_arg_3;

	is_not_nil_arg_1 = self & IND_NIL_NIL;
	is_not_nil_arg_2 = self & NIL_DIR_NIL || self & NIL_REG_NIL;
	is_not_nil_arg_3 = self & NIL_NIL_REG;
	return (conclusion);
}
