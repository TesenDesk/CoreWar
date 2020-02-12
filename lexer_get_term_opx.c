#include "lexer.h"
#include "token_defines.h"

int					lexer_get_term_opx(t_lexer *lexer, char const **text,
					int *token_type, void *token_ptr[2])
{
	(void)token_ptr;
	(void)token_type;
	while (**text != '\0' && ft_strchr(WHITE_SPACE, **text))
		++(*text);
	if (**text == REGISTER_CHAR)
	{
		(*text) += 1;
		return (REGISTER_CHAR_CODE);
	}
	if (ft_isdigit(**text))
	{
		(*text) += 1;
		return (INTEGER_CODE);
	}
	if ((**text == '-' || **text == '-') && ft_atoi(text) != 0)
	{
		(*text) += 2;
		return (INTEGER_CODE);
	}
	if (**text == LABEL_CHAR)
	{
		(*text) += 1;
		return (LABEL_CHAR_CODE);
	}
	if (**text == DIRECT_CHAR)
	{
		(*text) += 1;
		return (DIRECT_CHAR_CODE);
	}
	else
		return (TERM_UNDEFINED);
}