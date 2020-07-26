/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_find_2_0_layer_op.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 19:40:49 by ftothmur          #+#    #+#             */
/*   Updated: 2020/07/26 19:41:36 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

int	prvt_find_2_0_layer_op(t_parser *parser, int token_type)
{
	if (token_type == TOKEN_TREG)
	{
		if (parser->state == PARSER_OP1_LOAD_ST
		|| parser->state == PARSER_OP1_STORE_ST)
			return (PARSER_LINE_END_ST);
	}
	else if (token_type == TOKEN_TIND_LAB || token_type == TOKEN_TIND_INT)
	{
		if (parser->state == PARSER_OP1_STORE_ST)
			return (PARSER_LINE_END_ST);
	}
	return (PARSER_ERROR);
}
