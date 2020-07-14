// #include "lexer.h"
#include "prvt_lexer.h"
// #include "token_defines.h"

/*
**	The function determins if this part of text is appropriate term for
**	tind_integer token and set token_ptr.
**	INPUT:	Pointer to text WHITE_SPACE, SEPARATOR_CHAR, LINE_FEED or OTHER.
**	OUTPUT:	type of term.
*/

int			lexer_get_term_arg_break(t_lexer *lexer, char const **text,
			int *type, void *token_ptr[2])
{
	(void)lexer;
	(void)token_ptr;
	(void)type;
	if (**text == SEPARATOR_CHAR)
	{
		(*text)++;
		return (SEPARATOR_CHAR_CODE);
	}
	if (**text == LINE_FEED)
	{
		(*text)++;
		*type = TOKEN_LFEED;
		return (LINE_FEED_CODE);
	}
	else
		return (TERM_UNDEFINED_CODE);
}