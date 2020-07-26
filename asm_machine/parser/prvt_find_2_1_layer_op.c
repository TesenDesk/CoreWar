/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_find_2_1_layer_op.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 19:42:13 by ftothmur          #+#    #+#             */
/*   Updated: 2020/07/26 19:42:52 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

int	prvt_find_2_1_layer_op(t_parser *parser, int token_type)
{
	if (token_type == TOKEN_TREG && parser->state == PARSER_OP1_ARITHM_ST)
		return (PARSER_OP2_ARITHM_ST);
	else if (token_type == TOKEN_TREG && parser->state == PARSER_OP1_LOADI_ST)
		return (PARSER_OP2_LOADI_ST);
	else if (token_type == TOKEN_TREG && parser->state == PARSER_OP1_LOGIC_ST)
		return (PARSER_OP2_LOGIC_ST);
	else if (token_type == TOKEN_TREG && parser->state == PARSER_OP1_STORI_ST)
		return (PARSER_OP2_STORI_ST);
	else if (token_type == TOKEN_TDIR_LAB || token_type == TOKEN_TDIR_INT)
	{
		if (parser->state == PARSER_OP1_LOADI_ST)
			return (PARSER_OP2_LOADI_ST);
		else if (parser->state == PARSER_OP1_LOGIC_ST)
			return (PARSER_OP2_LOGIC_ST);
		else if (parser->state == PARSER_OP1_STORI_ST)
			return (PARSER_OP2_STORI_ST);
	}
	else if (token_type == TOKEN_TIND_LAB || token_type == TOKEN_TIND_INT)
	{
		if (parser->state == PARSER_OP1_LOGIC_ST)
			return (PARSER_OP2_LOGIC_ST);
		else if (parser->state == PARSER_OP1_STORI_ST)
			return (PARSER_OP2_STORI_ST);
	}
	return (PARSER_ERROR);
}
