/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_get_token_line_end.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 17:08:14 by ftothmur          #+#    #+#             */
/*   Updated: 2020/02/21 17:15:19 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expr.h"
#include "expr_defines.h"
#include "expr_private.h"
#include "parser_private.h"

int				parser_get_token_line_end(t_parser *parser, t_lexer *lexer,
				t_expr *expr, char const **text)
{
	int		token_type;

	token_type = get_type(lexer_form_token(lexer, text));
	if (!(token_type == TOKEN_LFEED))
		expr->token = EXPR_UNDEF;
	return (token_type);
}