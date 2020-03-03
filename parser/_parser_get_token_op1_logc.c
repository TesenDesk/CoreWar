// #include "expr.h"
// #include "expr_defines.h"
// #include "expr_private.h"
#include "parser_private.h"

int			_parser_get_token_op1_logc(t_parser *parser, t_lexer *lexer,
			t_expr *expr, char const **text)
{
	t_token		*token;
	int			token_type;
//	t_lexer*    lexer   = lexer_singleton_instance(LEXER_INSTANTIATE);

	if ((token = lexer_form_token(lexer, text)) == NULL)
		return (NO_TOKEN);
	if (token_type != TOKEN_TDIR_INT && token_type != TOKEN_TDIR_LAB &&
			token_type != TOKEN_TIND_INT && token_type != TOKEN_TIND_LAB &&
			token_type != TOKEN_TREG)
		expr->type = EXPR_UNDEF;
	expr_set_arg(expr, token, SECOND_ARG, token_type);
	return (token_type);
}