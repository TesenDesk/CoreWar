/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _types_not_nil_not_nil_reg.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 00:50:01 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/14 22:17:24 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_types.h"

int				_types_not_nil_not_nil_reg(int self)
{
	int			conclusion;
	int			is_not_nil_arg_1;
	int			is_not_nil_arg_2;
	int			is_not_nil_arg_3;

	is_not_nil_arg_1 = self & IND_NIL_NIL;
	is_not_nil_arg_2 = self & NIL_IND_NIL;
	is_not_nil_arg_3 = self & NIL_NIL_REG;
	conclusion = is_not_nil_arg_1 && is_not_nil_arg_2 && is_not_nil_arg_3; 
	return (conclusion);
}
