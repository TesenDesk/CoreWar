/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_do_match_op_logic.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 00:59:35 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/14 22:28:26 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_types.h"

int				types_do_match_op_logic(int self)
{
	int			conclusion;

	conclusion = types_not_nil_not_nil_reg(self);
	return (conclusion);
}
