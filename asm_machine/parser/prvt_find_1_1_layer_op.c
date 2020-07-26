/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_find_1_1_layer_op.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 19:39:58 by ftothmur          #+#    #+#             */
/*   Updated: 2020/07/26 19:41:34 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

int	prvt_find_1_1_layer_op(t_parser *parser, int token_type)
{
	if (token_type == TOKEN_TREG)
	{
		if (parser->state == PARSER_OP0_ARITHM_ST)
			return (PARSER_OP1_ARITHM_ST);
		else if (parser->state == PARSER_OP0_STORE_ST)
			return (PARSER_OP1_STORE_ST);
		else if (parser->state == PARSER_OP0_STORI_ST)
			return (PARSER_OP1_STORI_ST);
		else if (parser->state == PARSER_OP0_LOADI_ST)
			return (PARSER_OP1_LOADI_ST);
		else if (parser->state == PARSER_OP0_LOGIC_ST)
			return (PARSER_OP1_LOGIC_ST);
	}
	else if (token_type == TOKEN_TDIR_LAB || token_type == TOKEN_TDIR_INT
	|| token_type == TOKEN_TIND_LAB || token_type == TOKEN_TIND_INT)
	{
		if (parser->state == PARSER_OP0_LOAD_ST)
			return (PARSER_OP1_LOAD_ST);
		else if (parser->state == PARSER_OP0_LOADI_ST)
			return (PARSER_OP1_LOADI_ST);
		else if (parser->state == PARSER_OP0_LOGIC_ST)
			return (PARSER_OP1_LOGIC_ST);
	}
	return (PARSER_ERROR);
}
