/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_parser_get_token_init.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 13:58:43 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/17 16:31:09 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

static void			fill_expr_types(int expr_types[TOKEN_LABEL_WORD + 2])
{
	size_t			index_token;
	size_t			value_expr;

	index_token = TOKEN_CHNAME;
	value_expr = EXPR_CH_NAME_LINE;
	while (index_token <= TOKEN_STI && value_expr <= EXPR_OP_STRI)
		expr_types[index_token++] = value_expr++;
	while (index_token <= TOKEN_LLDI && value_expr <= EXPR_OP_LODI)
	{
		expr_types[index_token++] = value_expr;
		expr_types[index_token++] = value_expr++;
	}
	while (index_token <= TOKEN_XOR && value_expr == EXPR_OP_LOGC)
		expr_types[index_token++] = value_expr;
	value_expr++;
	while (index_token <= TOKEN_LFORK && value_expr == EXPR_OP_LIFE)
		expr_types[index_token++] = value_expr;
}

static void			find_arg_num(int token_type, char *arg_num)
{
	if (token_type == TOKEN_LABEL_WORD)
		*arg_num = LABEL_ARG;
	else if (token_type >= TOKEN_CHNAME
	&& token_type <= TOKEN_LFORK)
		*arg_num = OP_NAME;
	else if (token_type == TOKEN_LFEED)
		*arg_num = LINE_END;
	else
		*arg_num = JUNK;
}

t_token				*prvt_parser_get_token_init(t_parser *parser,
					t_lexer *lexer, t_expr *expr, char const **text)
{
	t_token			*token;
	int				token_type;
	static int		expr_types[COUNT_EXPR];
	char			arg_num;

	arg_num = 0;
	if ((token = lexer_form_token(lexer, text)) == NULL) {
//		token_destructor(&token);
//		return (NULL);
//		free(*token);
		exit(-1);;
	}
	token_type = token_get_type(token);
	find_arg_num(token_type, &arg_num);
	if (!expr_types[TOKEN_LFORK])
		fill_expr_types(expr_types);
	if (token_type >= TOKEN_CHNAME && token_type <= TOKEN_LFORK)
		expr->type = expr_types[token_type];
	else if (token_type == TOKEN_LABEL_WORD || token_type == TOKEN_EOF)
	{
		expr->type = (token_type == TOKEN_LABEL_WORD) ? EXPR_LABEL_W : EXPR_EOF;
		parser->state = (token_type == TOKEN_LABEL_WORD) ? PARSER_FINISH_ST
			: PARSER_FINISH_ST;
	}
	else
		expr->type = EXPR_UNDEF;
	if (expr_set_arg(expr, token, arg_num, token_type) == FAILURE)
		return (NULL);
	return (token);
}
