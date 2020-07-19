/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_parser_get_token_op1_lodi.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 15:57:57 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/15 15:57:57 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

t_token			*prvt_parser_get_token_op1_lodi(t_parser *parser,
				t_lexer *lexer, t_expr *expr, char const **text)
{
	t_token		*token;
	int			token_type;

	if ((token = lexer_form_token(lexer, text)) == NULL)
		return (NULL);
	token_type = token_get_type(token);
	if (!(token_type == TOKEN_TREG ||
			token_type == TOKEN_TDIR_INT || token_type == TOKEN_TDIR_LAB))
		expr->type = EXPR_UNDEF;
	if (expr_set_arg(expr, token, SECOND_ARG, token_type) == FAILURE)
		return (NULL);
	return (token);
}
