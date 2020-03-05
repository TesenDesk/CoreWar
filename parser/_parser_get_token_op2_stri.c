// #include "expr.h"
// #include "expr_defines.h"
// #include "expr_private.h"
#include "parser_private.h"

int					_parser_get_token_op2_stri(t_parser *parser, t_lexer *lexer,
					t_expr *expr, char const **text)
{
	t_token			*token;
	int				token_type;

	token_type = token_get_type(lexer_form_token(lexer, text));
	if (token_type != TOKEN_TREG ||
			token_type != TOKEN_TDIR_INT || token_type != TOKEN_TDIR_LAB)
		expr->type = EXPR_UNDEF;
	if (expr_set_arg(expr, token, OP_NAME, token_type) == FAILURE)
		return (NO_TOKEN);
	return (token_type);
}