/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_parser_change_state.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 13:36:30 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/26 19:49:32 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

void		prvt_parser_change_state(t_parser *parser, int token_type)
{
	if (parser->state == PARSER_INIT_ST)
		parser->state = prvt_parser_find_next_to_init_st(token_type);
	else if (parser->state == PARSER_OP0_LIFE_ST
	|| parser->state == PARSER_OP0_AFFECT_ST || parser->state ==
	PARSER_OP0_LOAD_ST || parser->state == PARSER_OP1_LOAD_ST
	|| parser->state == PARSER_OP0_STORE_ST || parser->state ==
	PARSER_OP1_STORE_ST || parser->state == PARSER_OP0_ARITHM_ST
	|| parser->state == PARSER_OP1_ARITHM_ST || parser->state ==
	PARSER_OP0_LOADI_ST || parser->state == PARSER_OP1_LOADI_ST
	|| parser->state == PARSER_OP0_LOGIC_ST || parser->state ==
	PARSER_OP1_LOGIC_ST || parser->state == PARSER_OP0_STORI_ST
	|| parser->state == PARSER_OP1_STORI_ST)
		prvt_parser_find_next_to_op01_st(parser, token_type);
	else if (parser->state == PARSER_OP2_ARITHM_ST
	|| parser->state == PARSER_OP2_LOADI_ST
	|| parser->state == PARSER_OP2_LOGIC_ST
	|| parser->state == PARSER_OP2_STORI_ST)
		parser->state = prvt_parser_find_next_to_op2_st(parser, token_type);
	else if (parser->state == PARSER_LINE_END_ST)
	{
		if (token_type == TOKEN_LFEED)
			parser->state = PARSER_FINISH_ST;
		else
			parser->state = PARSER_ERROR;
	}
}
