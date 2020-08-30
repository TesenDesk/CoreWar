/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_parser_get_token_op0_load.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 13:33:26 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/15 13:33:40 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

t_token			*prvt_parser_get_token_op0_load(t_parser *parser,
				t_lexer *lexer, t_expr *expr, char const **text)
{
	t_token		*token;
	int			token_type;

	(void)parser;
	if ((token = lexer_form_token(lexer, text)) == NULL)
		return (NULL);
	token_type = token_get_type(token);
	if (!(token_type == TOKEN_TDIR_INT || token_type == TOKEN_TDIR_LAB ||
			token_type == TOKEN_TIND_INT || token_type == TOKEN_TIND_LAB))
		expr->type = EXPR_UNDEF;
	if (expr_set_arg(expr, token, FIRST_ARG, token_type) == FAIL)
		return (NULL);
	return (token);
}
