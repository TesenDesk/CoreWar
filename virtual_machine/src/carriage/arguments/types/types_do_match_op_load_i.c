/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_do_match_op_load_i.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 00:59:05 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/14 22:28:11 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_types.h"

int				_types_do_match_op_load_i(int self)
{
	int			conclusion;

	conclusion = types_not_nil_dir_or_reg_reg(self);
return (conclusion);
}
