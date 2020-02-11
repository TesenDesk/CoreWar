#include "token_defines.h"

int		lexer_get_t_ind_integer(t_lexer *lexer, char const **text, int *token_type, void *token_ptr[2])
{
	void	*t;

	t = (void*)lexer;
	token_ptr[0] = *text;
	if (**text == '+' || **text == '-')
	{
		++(*text);
		if (!ft_isdigit(**text))
		{
			token_type = TOKEN_UNDEF;
			return (TERM_UNDEFINED);
		}
	}
	token_type = TOKEN_TIND_INT;
	while (ft_isdig(**text))
		++(*text);
	token_ptr[1] = *text - 1;
	return (INTEGER_CODE);
}

int		lexer_get_t_ind_label(t_lexer *lexer, char const **text,
		int *token_type, void *token_ptr[2])
{
	void	*t;

	t = (void*)lexer;
	++(*text);
	token_ptr[0] = *text;
	if (!ft_strchr(LABEL_CHARS, **text))
	{
		*token_type = TOKEN_UNDEF;
		return (TERM_UNDEFINED)
	}
	else
	{
		token_type = TOKEN_TIND_LAB;
		while (ft_strchr(LABEL_CHARS, **text))
			++(*text);
		token_ptr[1] = *text - 1;
		return (LABEL_CHARS_CODE);
	}
}

int			tkn_get_break(t_lexer *lexer, char const **text,
			int *token_type, void *token_ptr[2])
{
	if (ft_strchr(WHITE_SPACE, **text)
	{
		(*text)++;
		return (WHITE_SPACE_CODE);
	}
	if (**text == SEPARATOR_CHAR)
	{
		(*text)++;
		return (SEPARATOR_CHAR_CODE);
	}
	if (**text == LINE_END)
	{
		(*text)++;
		return ();
	}
	if (**text == '\0')
		return ();
	else
		return (TERM_UNDEFINED)
}