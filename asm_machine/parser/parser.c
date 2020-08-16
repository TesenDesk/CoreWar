/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 14:48:44 by cmissy            #+#    #+#             */
/*   Updated: 2020/08/16 15:37:43 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

static void			fill_expr_ar_num(int expr_ar_num[COUNT_EXPR])
{
	expr_ar_num[EXPR_OP_LIFE] = 1;
	expr_ar_num[EXPR_OP_AFCT] = 1;
	expr_ar_num[EXPR_OP_LOAD] = 2;
	expr_ar_num[EXPR_OP_STOR] = 2;
	expr_ar_num[EXPR_OP_ARIT] = 3;
	expr_ar_num[EXPR_OP_LODI] = 3;
	expr_ar_num[EXPR_OP_LOGC] = 3;
	expr_ar_num[EXPR_OP_STRI] = 3;
}

static t_expr		*expr_fill_arg_num(t_expr *expr)
{
	static int		expr_ar_num[COUNT_EXPR];

	if (!(expr_ar_num[EXPR_OP_AFCT]))
		fill_expr_ar_num(expr_ar_num);
	expr->arg_size = expr_ar_num[expr->type];
	return (expr);
}

t_expr				*parser_form_expr(t_parser *parser, char const **text,
		t_hash_map *map, t_vector *label_vector)
{
	t_expr			*expr;
	t_token			*token;
	int				token_type;

	expr = expr_ctor();
	while (TRUE)
	{
		token = parser->get_token[parser->state](parser,
				lexer_singleton_instance(LEXER_INSTANTIATE), expr, text);
		if ((token_type = token_get_type(token)) == TOKEN_LABEL_WORD)
			if (label_checker_put_to_map_label_word(&map, token) == FAILURE)
				exit(-1);
		else if (token_type == TOKEN_TIND_LAB || token_type == TOKEN_TDIR_LAB)
		{
			if (label_checker_put_to_map_label_ptr(label_vector, token)
					== FAILURE)
				exit(-1);
		}
		parser->change_state(parser, token_type);
		if (parser->state == PARSER_FINISH_ST || parser->state == PARSER_ERROR)
			break ;
	}
	expr->type = (parser->state == PARSER_ERROR) ? EXPR_UNDEF : expr->type;
	parser->state = PARSER_INIT_ST;
	return (expr_fill_arg_num(expr));
}
