#include "expr.h"
#include "expr_defines.h"
#include "expr_private.h"
#include "parser_private.h"

int					parser_get_token_op_stri2(t_parser *parser, t_lexer *lexer,
					t_expr *expr, char const **text)
{
	int			token_type;

	token_type = get_type(lexer_form_token(lexer, text));
	if (token_type != TOKEN_TREG ||
	token_type != TOKEN_TDIR_INT || token_type != TOKEN_TDIR_LAB)
		expr->type = EXPR_UNDEF;
	return (token_type);
}