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
		expr->type = EXPR_CH_NAME_LINE;
	else if (token_type == TOKEN_CHCOM)
		expr->type = EXPR_CH_COMMENT_LINE;
	else if (token_type == TOKEN_LFEED)
		expr->type = EXPR_PRECODE_COMMENT_LINE;
	else if (token_type == TOKEN_LAB_WO)
		expr->type = EXPR_CODE_COMMENT_LINE;

	else if (token_type == TOKEN_LIVE || token_type == TOKEN_ZJMP ||
	token_type == TOKEN_FORK || token_type == TOKEN_LFORK)
		expr->type = EXPR_OP_LIFE;
	else if (token_type == TOKEN_AFF)
		expr->type = EXPR_OP_AFCT;
	else if (token_type == TOKEN_LD || token_type == TOKEN_LLD)
		expr->type = EXPR_OP_LOAD;
	else if (token_type == TOKEN_ST)
		expr->type = EXPR_OP_STOR;
	else if (token_type == TOKEN_ADD || token_type == TOKEN_SUB)
		expr->type = EXPR_OP_ARIT;
	else if (token_type == TOKEN_LDI || token_type == TOKEN_LLDI)
		expr->type = EXPR_OP_LODI;
	else if (token_type == TOKEN_AND || token_type == TOKEN_OR ||
	token_type == TOKEN_XOR)
		expr->type = EXPR_OP_LOGC;
	else if (token_type == TOKEN_STI)
		expr->type = EXPR_OP_STRI;

	else
		expr->type = EXPR_UNDEF;
	return (token_type);
}
