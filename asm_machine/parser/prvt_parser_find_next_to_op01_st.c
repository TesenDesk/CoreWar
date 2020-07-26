/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_parser_find_next_to_op01_st.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 19:43:08 by ftothmur          #+#    #+#             */
/*   Updated: 2020/07/26 19:43:24 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

int	prvt_parser_find_next_to_op01_st(t_parser *parser, int token_type)
{
	if (parser->state == PARSER_OP0_LIFE_ST
	|| parser->state == PARSER_OP0_AFFECT_ST)
		parser->state = prvt_find_1_0_layer_op(parser, token_type);
	else if (parser->state == PARSER_OP0_LOAD_ST
	|| parser->state == PARSER_OP0_ARITHM_ST
	|| parser->state == PARSER_OP0_LOADI_ST
	|| parser->state == PARSER_OP0_LOGIC_ST
	|| parser->state == PARSER_OP0_STORI_ST
	|| parser->state == PARSER_OP0_STORE_ST)
		parser->state = prvt_find_1_1_layer_op(parser, token_type);
	else if (parser->state == PARSER_OP1_LOAD_ST
	|| parser->state == PARSER_OP1_STORE_ST)
		parser->state = prvt_find_2_0_layer_op(parser, token_type);
	else if (parser->state == PARSER_OP1_ARITHM_ST
	|| parser->state == PARSER_OP1_LOADI_ST
	|| parser->state == PARSER_OP1_LOGIC_ST
	|| parser->state == PARSER_OP1_STORI_ST)
		parser->state = prvt_find_2_1_layer_op(parser, token_type);
	else if (parser->state == PARSER_LINE_END_ST)
		parser->state = PARSER_FINISH_ST;
	else
		parser->state = PARSER_ERROR;
	return (SUCCESS);
}
