// #include "lexer.h"
// #include "token_defines.h"
#include "prvt_lexer.h"

int				lexer_get_term_arg_dir_int(t_lexer *lexer, char const **text,
				int *type, void *token_ptr[2])
{
	int sign = 0;

	if (**text == LABEL_CHAR)
	{
		++(*text);
		return (LABEL_CHAR_CODE);
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
		*type = TOKEN_TDIR_INT;
		return (INTEGER_CODE);
	}
	else
	{
		*type = TOKEN_UNDEF;
		return (LABEL_CHAR_CODE);
	}
}

int				lexer_get_term_arg_dir_label(t_lexer *lexer, char const **text,
				int *type, void *token_ptr[2])
{
	(void)lexer;
	if (!ft_strchr(LABEL_CHARS, **text))
	{
		*type = TOKEN_UNDEF;
		return (TERM_UNDEFINED_CODE);
	}
	token_ptr[TOKEN_START_PTR] = (void*)*text;
	*type = TOKEN_TDIR_LAB;
	while (ft_strchr(LABEL_CHARS, **text))
		++(*text);
	token_ptr[TOKEN_END_PTR] = (void*)(*text - 1);
	return (LABEL_CHARS_CODE);
}