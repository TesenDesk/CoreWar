//#include "lexer.h"
#include "lexer_private.h"
#include "token_defines.h"

int					lexer_get_term_opx(t_lexer *lexer, char const **text,
					int *type, void *token_ptr[2])
{
	int sign = 0;

	(void)lexer;
	// *type = TOKEN_OPX;
	while (**text != '\0' && (ft_strchr(WHITE_SPACE, **text) || **text == '\n'))
		++(*text);
	if (**text == REGISTER_CHAR)
	{
		(*text) += 1;
		return (REGISTER_CHAR_CODE);
	}
	if ((**text == '+' || **text == '-'))
	{
		sign = **text == '+' ? 1 : -1;
		token_ptr[TOKEN_TEXT_START_INDX] = (void*)*text;
		++(*text);
	}
	if (ft_isdigit(**text))
	{
		if (!(sign))
			*token_ptr = (void*)*text;
		while (ft_isdigit(**text))
			++(*text);
		token_ptr[TOKEN_TEXT_END_INDX] = (void*)(*text - 1);
		return (INTEGER_CODE);
	}
	else if (sign)
	{
		++(*text);
		*type = TOKEN_UNDEF;
		return (TERM_UNDEFINED_CODE);
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
		return (TERM_UNDEFINED_CODE);
}

int					lexer_get_term_multi_arg(t_lexer *lexer, char const **text,
					int *type, void *token_ptr[2])
{
	int sign = 0;

	(void)type;
	(void)lexer;
	while (**text != '\0' && (ft_strchr(WHITE_SPACE, **text) || **text == '\n'))
		++(*text);
	if (**text == REGISTER_CHAR)
	{
		(*text) += 1;
		return (REGISTER_CHAR_CODE);
	}
	if ((**text == '+' || **text == '-'))
	{
		sign = **text == '+' ? 1 : -1;
		*token_ptr = (void*)*text;
		++(*text);
	}
	if (ft_isdigit(**text))
	{
		if (!(sign))
			*token_ptr = (void*)*text;
		while (ft_isdigit(**text))
			++(*text);
		*(token_ptr + 1) = (void*)(*text - 1);
		return (INTEGER_CODE);
	}
	else if (sign)
	{
		++(*text);
		*type = TOKEN_UNDEF;
		return (TERM_UNDEFINED_CODE);
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
		return (TERM_UNDEFINED_CODE);
}
