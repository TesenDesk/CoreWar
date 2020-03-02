//#include "lexer.h"
//#include "token_defines.h"
#include "lexer_private.h"

int				lexer_get_term_arg_ind_int(t_lexer *lexer, char const **text,
					int *type, void *token_ptr[2])
{
	(void)lexer;
	(void)token_ptr;
	(void)type;
	*type = TOKEN_TIND_INT;
	if (ft_strchr(WHITE_SPACE, **text))
	{
		++(*text);
		return (WHITE_SPACE_CODE);
	}
	else if (**text == SEPARATOR_CHAR)
	{
		++(*text);
		return (SEPARATOR_CHAR_CODE);
	}
	// else if (**text == LINE_FEED)
	// {
	// 	++(*text);
	// 	return (LINE_FEED_CODE);
	// }
	// *type = TOKEN_UNDEF;
	return (TERM_UNDEFINED_CODE);
}

int					lexer_get_term_arg_ind_label(t_lexer *lexer, char const **text,
					int *type, void *token_ptr[2])
{
	(void)lexer;
	if (!ft_strchr(LABEL_CHARS, **text))
	{
		*type = TOKEN_UNDEF;
		return (TERM_UNDEFINED_CODE);
	}
	token_ptr[TOKEN_START_PTR] = (void*)*text;
	*type = TOKEN_TIND_LAB;
	while (ft_strchr(LABEL_CHARS, **text))
		++(*text);
	token_ptr[TOKEN_END_PTR] = (void*)(*text - 1);
	return (LABEL_CHARS_CODE);
}
