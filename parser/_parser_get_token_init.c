// #include "expr.h"
// #include "expr_defines.h"
// #include "expr_private.h"
#include "parser_private.h"

static void		fill_expr_types(int expr_types[TOKEN_LABEL_WORD + 2])
{
	size_t		index_token;
	size_t		value_expr;

	index_token = TOKEN_LFEED;
	value_expr = EXPR_LFEED;
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

int				_parser_get_token_init(t_parser *parser, t_lexer *lexer,
				t_expr *expr, char const **text)
{
	t_token		*token;
	int			token_type;
	static int	expr_types[TOKEN_LFORK + 1];

	if ((token = lexer_form_token(lexer, text)) == NULL)
		return (NO_TOKEN);
	token_type = token_get_type(token);
	if (!expr_types[TOKEN_LFORK])
		fill_expr_types(expr_types);
	if (token_type >= TOKEN_LFEED && token_type <= TOKEN_LFORK)
		expr->type = expr_types[token_type];
	else if (token_type == TOKEN_EOF)
		expr->type = EXPR_EOF;
	else
		expr->type = EXPR_UNDEF;
	if (expr_set_arg(expr, token, OP_NAME, token_type) == FAILURE)
		return (NO_TOKEN);
	return (token_type);
}
