/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_do_match_op_load.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 00:56:37 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/14 22:28:19 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_types.h"

int				types_do_match_op_load(int self)
{
	int			conclusion;

	conclusion = (self == DIR_REG_NIL || self == IND_REG_NIL);
	return (conclusion);
}
