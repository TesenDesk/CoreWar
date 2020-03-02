// #include "expr.h"
// #include "expr_defines.h"
// #include "expr_private.h"
#include "parser_private.h"

int					_parser_get_token_op0_stri(t_parser *parser, t_lexer *lexer,
					t_expr *expr, char const **text)
{
	int			token_type;

	token_type = token_get_type(lexer_form_token(lexer, text));
	if (token_type != TOKEN_TREG)
		expr->type = EXPR_UNDEF;
	return (token_type);
}
