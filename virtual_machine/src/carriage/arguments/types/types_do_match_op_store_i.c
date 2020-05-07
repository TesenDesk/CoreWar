/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_do_match_op_store_ii.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 00:58:34 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/14 22:28:32 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_types.h"

int				types_do_match_op_sti(int self)
{
	int			conclusion;

	conclusion = (self == REG_DIR_DIR || self == REG_REG_DIR);
	return (conclusion);
}
