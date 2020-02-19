#include "expr.h"
#include "expr_defines.h"
#include "expr_private.h"
#include "parser_private.h"

int			parser_get_token_init(t_parser *parser, t_lexer *lexer,
			t_expr *expr, char const **text)
{
	int		token_type;

	expr->begin = *text;
	token_type = get_type(lexer_form_token(lexer, text));
	if (token_type == TOKEN_CHNAME)
		expr->token = EXPR_CH_NAME_LINE;
	else if (token_type == TOKEN_CHCOM)
		expr->token = EXPR_CH_COMMENT_LINE;
	else if (token_type == TOKEN_LFEED)
		expr->token = EXPR_PRECODE_COMMENT_LINE;
	else if (token_type == TOKEN_OPX)
		expr->token = ??????????;
	else if (token_type == TOKEN_LAB_WO)
		expr->token = EXPR_CODE_COMMENT_LINE;
	else
		expr->token = EXPR_UNDEF;
	return (token_type);
}
