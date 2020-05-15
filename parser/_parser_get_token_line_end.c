/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parser_get_token_line_end.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita_toropov <nikita_toropov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 17:08:14 by ftothmur          #+#    #+#             */
/*   Updated: 2020/03/23 13:56:52 by nikita_toro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "expr.h"
// #include "expr_defines.h"
// #include "expr_private.h"
#include "parser_private.h"

t_token			*_parser_get_token_line_end(t_parser *parser, t_lexer *lexer,
				t_expr *expr, char const **text)
{

	t_token		*token;
	int			token_type;
	if ((token = lexer_form_token(lexer, text)) == NULL)
		return (NULL);
	token_type = token_get_type(token);
	if (!(token_type == TOKEN_LFEED))
		expr->type = EXPR_UNDEF;
	if (expr_set_arg(expr, token, LINE_END_ARG, token_type) == FAILURE)
	{
		return (NULL);
	}
	return (token);
}