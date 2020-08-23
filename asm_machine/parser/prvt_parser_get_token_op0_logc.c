/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_parser_get_token_op0_logc.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 13:56:47 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/15 13:56:49 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

t_token		*prvt_parser_get_token_op0_logc(t_parser *parser, t_lexer *lexer,
											t_expr *expr, char const **text)
{
	t_token	*token;
	int		token_type;

	if ((token = lexer_form_token(lexer, text)) == NULL)
		return (NULL);
	token_type = token_get_type(token);
	if (token_type != TOKEN_TDIR_INT && token_type != TOKEN_TDIR_LAB &&
		token_type != TOKEN_TIND_INT && token_type != TOKEN_TIND_LAB &&
		token_type != TOKEN_TREG)
		expr->type = EXPR_UNDEF;
	if (expr_set_arg(expr, token, FIRST_ARG, token_type) == FAIL)
		return (NULL);
	return (token);
}
