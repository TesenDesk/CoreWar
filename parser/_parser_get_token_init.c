// #include "expr.h"
#include "expr_defines.h"
// #include "expr_private.h"
#include "parser_private.h"

void		fill_expr_types(int expr_types[TOKEN_LABEL_WORD + 2])
{
	expr_types[ ] = 
	expr_types[] = 
	expr_types[] = 
	expr_types[] = 
	expr_types[] = 
	expr_types[] = 
	expr_types[] = 
	expr_types[] = 
	expr_types[] = 
	expr_types[] = 
	expr_types[] = 
	expr_types[] = 
	expr_types[] = 
	expr_types[] = 
	expr_types[] = 
	expr_types[] = 
	expr_types[] = 
	expr_types[] = 
}


int			_parser_get_token_init(t_parser *parser, t_lexer *lexer,
			t_expr *expr, char const **text)
{
	// int		token_type;

	// token_type = token_get_type(lexer_form_token(lexer, text));
	t_token		*token;
	int			token_type;
	int			current_token_type;
	int			expr_types[TOKEN_LABEL_WORD + 2];

	if ((token = lexer_form_token(lexer, text)) == NULL)
		return (NO_TOKEN);
	token_type = token_get_type(token);
	current_token_type = TOKEN_LFEED;
	fill_expr_types(expr_types[TOKEN_LABEL_WORD + 2]);
	while (current_token_type <= TOKEN_LABEL_WORD)
	{
		if (token_type == current_token_type)
			expr->type = expr_types[current_token_type];
			break ;
		current_token_type++;
	}
	expr_set_arg(expr, token, OP_NAME, token_type);
	// if (token_type == TOKEN_CHNAME)
	// 	expr->type = EXPR_CH_NAME_LINE;
	// else if (token_type == TOKEN_CHCOM)
	// 	expr->type = EXPR_CH_COMMENT_LINE;
	// else if (token_type == TOKEN_LFEED)
	// 	expr->type = EXPR_PRECODE_COMMENT_LINE;
	// else if (token_type == TOKEN_LABEL_WORD)
	// 	expr->type = EXPR_CODE_COMMENT_LINE;
	// else if (token_type == TOKEN_LIVE || token_type == TOKEN_ZJMP ||
	// token_type == TOKEN_FORK || token_type == TOKEN_LFORK)
	// 	expr->type = EXPR_OP_LIFE;
	// else if (token_type == TOKEN_AFF)
	// 	expr->type = EXPR_OP_AFCT;
	// else if (token_type == TOKEN_LD || token_type == TOKEN_LLD)
	// 	expr->type = EXPR_OP_LOAD;
	// else if (token_type == TOKEN_ST)
	// 	expr->type = EXPR_OP_STOR;
	// else if (token_type == TOKEN_ADD || token_type == TOKEN_SUB)
	// 	expr->type = EXPR_OP_ARIT;
	// else if (token_type == TOKEN_LDI || token_type == TOKEN_LLDI)
	// 	expr->type = EXPR_OP_LODI;
	// else if (token_type == TOKEN_AND || token_type == TOKEN_OR ||
	// token_type == TOKEN_XOR)
	// 	expr->type = EXPR_OP_LOGC;
	// else if (token_type == TOKEN_STI)
	// 	expr->type = EXPR_OP_STRI;
	// else
	// 	expr->type = EXPR_UNDEF;
	return (token_type);
}
