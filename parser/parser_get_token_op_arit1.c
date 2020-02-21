/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_get_token_op_arit1.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:45:37 by ftothmur          #+#    #+#             */
/*   Updated: 2020/02/21 15:48:45 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expr.h"
#include "expr_defines.h"
#include "expr_private.h"
#include "parser_private.h"

int				parser_get_token_op_arit1(t_parser *parser, t_lexer *lexer,
				t_expr *expr, char const **text)
{
	int		token_type;

	token_type = get_type(lexer_form_token(lexer, text));
	if (!(token_type == TOKEN_TREG))
		expr->token = EXPR_UNDEF;
	return (token_type);
}