/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parser_get_token_op1_stor.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 17:08:14 by ftothmur          #+#    #+#             */
/*   Updated: 2020/03/03 18:57:10 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "expr.h"
// #include "expr_defines.h"
// #include "expr_private.h"
#include "parser_private.h"

int				_parser_get_token_op1_stor(t_parser *parser, t_lexer *lexer,
				t_expr *expr, char const **text)
{
	t_token		*token;
	int			token_type;

	if ((token = lexer_form_token(lexer, text)) == NULL)
		return (NO_TOKEN);
	token_type = token_get_type(token);
	if (!(token_type == TOKEN_TREG ||
			token_type == TOKEN_TIND_INT || token_type == TOKEN_TIND_LAB))
		expr->type = EXPR_UNDEF;
	expr_set_arg(expr, token, SECOND_ARG, token_type);
	return (token_type);
}