#include "lexer.h"
#include "token_defines.h"
#include "lexer_private.h"

int					lexer_get_term_line_feed(t_lexer *lexer, char const **text,
					int *type, void *token_ptr[2])
{
	if (**text != LINE_FEED)
		return (TERM_UNDEFINED_CODE);
	while (**text == LINE_FEED)
		++(*text);
	*type = LINE_FEED_CODE;
	return (LINE_FEED_CODE);
}
