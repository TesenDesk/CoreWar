/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_do_match_op_arithmetic.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 00:56:06 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/14 22:26:18 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_types.h"

int				types_do_match_op_arithmetic(int self)
{
	int			conclusion;

	conclusion = self == REG_REG_REG;
	return (conclusion);
}
