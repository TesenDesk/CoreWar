/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_parser_get_token_eof.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 15:55:20 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/15 15:55:20 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

t_token			*prvt_parser_get_token_eof(t_parser *parser, t_lexer *lexer,
				t_expr *expr, char const **text)
{
	t_token		*token;
	int			token_type;

	if ((token = lexer_form_token(lexer, text)) == NULL)
		return (NULL);
	token_type = token_get_type(token);
	if (!(token_type == TOKEN_EOF))
		expr->type = EXPR_UNDEF;
	if (expr_set_arg(expr, token, OP_NAME, token_type) == FAILURE)
		return (NULL);
	return (token);
}
