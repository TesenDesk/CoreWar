#include "lexer.h"
#include "token_defines.h"

int					lexer_get_term_opx(t_lexer *lexer, char const **text,
					int *token_type, void *token_ptr[2])
{
	// printf("\ntext - %s\n\n", *text);
	*token_type = TOKEN_OPX;
	// while (**text != '\0' && ft_strchr(WHITE_SPACE, **text))
	while (**text != '\0' && (ft_strchr(WHITE_SPACE, **text) || **text == '\n'))
		++(*text);
	if (**text == REGISTER_CHAR)
	{
		(*text) += 1;
		return (REGISTER_CHAR_CODE);
	}
	int sign = 0;
	if ((**text == '+' || **text == '-'))
	{
		sign = **text == '+' ? 1 : -1;
		*token_ptr = *text;
		++(*text);
	}
	if (ft_isdigit(**text))
	{
		printf("HELLO THERE %s\n", *text);
		if (!(sign))
			*token_ptr = *text;
		while (ft_isdigit(**text))
			++(*text);
		*(token_ptr + 1) = *text - 1;
		return (INTEGER_CODE);
	}
	else if (sign)
	{
		++(*text);
		*token_type = TOKEN_UNDEF;
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
