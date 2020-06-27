/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parser_get_token_op0_life.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:28:05 by ftothmur          #+#    #+#             */
/*   Updated: 2020/03/05 21:35:51 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "_expr.h"
 #include "expr_defines.h"
 #include "expr_private.h"
#include "parser_private.h"

t_token			*_parser_get_token_op0_life(t_parser *parser, t_lexer *lexer,
				t_expr *expr, char const **text)
{
	t_token		*token;
	int			token_type;

	if ((token = lexer_form_token(lexer, text)) == NULL)
		return (NULL);
	token_type = token_get_type(token);
	if (!(token_type == TOKEN_TDIR_INT || token_type == TOKEN_TDIR_LAB))
		expr->type = EXPR_UNDEF;
	if (expr_set_arg(expr, token, FIRST_ARG, token_type) == FAILURE)
		return (NULL);
	return (token);
}