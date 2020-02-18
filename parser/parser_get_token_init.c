#include "parser_private.h"

int				parser_get_token_init(struct s_parser *parser, t_lexer *lexer, char const **text)
{
	int			token_type;

	token_type = get_token_type(lexer_form_token(lexer, text));
	if (token_type == TOKEN_CHNAME || token_type == TOKEN_CHCOM)
		return ();
	else if (token_type == TOKEN_OPX)
		return ();
	else if (token_type == TOKEN_LFEED)
		return ();
	else if (token_type == TOKEN_LAWO) /// WHERE???
		return ();
	else if (token_type == TOKEN_LAWO) /// WHERE???
		return ();
}