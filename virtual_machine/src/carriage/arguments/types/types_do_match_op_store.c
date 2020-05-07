/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_do_match_op_store.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 00:57:55 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/14 22:28:38 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_types.h"

int				types_do_match_op_store(int self)
{
	int			conclusion;

	conclusion = (self == REG_IND_NIL || self == REG_REG_NIL);
	return (conclusion);
}
