/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_find_1_0_layer_op.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 19:37:33 by ftothmur          #+#    #+#             */
/*   Updated: 2020/07/26 19:41:31 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

int	prvt_find_1_0_layer_op(t_parser *parser, int token_type)
{
	if ((parser->state == PARSER_OP0_LIFE_ST && (token_type == TOKEN_TDIR_INT
	|| token_type == TOKEN_TDIR_LAB)) || (parser->state == PARSER_OP0_AFFECT_ST
	&& token_type == TOKEN_TREG))
		return (PARSER_LINE_END_ST);
	return (PARSER_ERROR);
}
