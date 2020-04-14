/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_do_match_op_affect.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 00:55:06 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/14 22:13:36 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_types.h"

int				types_do_match_op_affect(int self)
{
	int			conclusion;

	conclusion = self == REG_NIL_NIL;
	return (conclusion);
}
