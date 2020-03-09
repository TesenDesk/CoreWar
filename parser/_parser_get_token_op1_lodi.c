/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parser_get_token_op1_lodi.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:15:45 by ftothmur          #+#    #+#             */
/*   Updated: 2020/03/05 21:43:01 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "expr.h"
// #include "expr_defines.h"
// #include "expr_private.h"
#include "parser_private.h"

int				_parser_get_token_op1_lodi(t_parser *parser, t_lexer *lexer,
				t_expr *expr, char const **text)
{
	t_token		*token;
	int			token_type;

	if ((token = lexer_form_token(lexer, text)) == NULL)
		return (NO_TOKEN);
	token_type = token_get_type(token);
	if (!(token_type == TOKEN_TREG ||
			token_type == TOKEN_TDIR_INT || token_type == TOKEN_TDIR_LAB))
		expr->type = EXPR_UNDEF;
	if (expr_set_arg(expr, token, OP_NAME, token_type) == FAILURE)
		return (NO_TOKEN);
	return (token_type);
}