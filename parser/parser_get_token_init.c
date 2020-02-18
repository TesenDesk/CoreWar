#include "expr.h"
#include "expr_defines.h"
#include "expr_private.h"
#include "parser_private.h"

int			parser_get_token_init(t_parser *parser, t_lexer *lexer,
			t_expr *expr, char const **text)
{
	int		token_type;

	token_type = get_type(lexer_form_token(lexer, text));
	if (token_type == TOKEN_CHNAME || token_type == TOKEN_CHCOM ||
	token_type == TOKEN_LFEED || token_type == TOKEN_LAB_WO ||
	token_type == TOKEN_OPX)
		expr->type = EXPR_INIT;
	else
		expr->type = EXPR_UNDEF;
	return (token_type);
}
