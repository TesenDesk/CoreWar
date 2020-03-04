/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parser_get_token_eof.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 17:08:14 by ftothmur          #+#    #+#             */
/*   Updated: 2020/03/04 20:37:49 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "expr.h"
// #include "expr_defines.h"
// #include "expr_private.h"
#include "parser_private.h"

int				_parser_get_token_eof(t_parser *parser, t_lexer *lexer,
				t_expr *expr, char const **text)
{
	t_token		*token;
	int			token_type;

	if ((token = lexer_form_token(lexer, text)) == NULL)
		return (NO_TOKEN);
	token_type = token_get_type(token);
	if (!(token_type == TOKEN_EOF))
		expr->type = EXPR_UNDEF;
	expr_set_arg(expr, token, OP_NAME, token_type);
	return (token_type);
}
