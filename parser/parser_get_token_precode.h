#include "expr.h"
#include "expr_defines.h"
#include "expr_private.h"
#include "parser_private.h"

int			parser_get_token_precode(t_parser *parser, t_lexer *lexer,
			t_expr *expr, char const **text)
{
	int		token_type;

	token_type = get_type(lexer_form_token(lexer, text));
	if (token_type == TOKEN_LFEED)
	{
		it (get_type(lexer_form_token(lexer, expr->begin)) == TOKEN_CHNAME)
			expr->type = EXPR_CH_NAME_LINE;
		else it (get_type(lexer_form_token(lexer, expr->begin)) == TOKEN_CHCOM)
			expr->type = EXPR_CH_COMMENT_LINE;
	}
	else
		expr->type = EXPR_UNDEF;
	return (token_type);
}
