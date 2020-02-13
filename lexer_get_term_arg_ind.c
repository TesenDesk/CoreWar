#include "lexer.h"
#include "token_defines.h"
#include "lexer_private.h"

int				lexer_get_term_arg_ind_int(t_lexer *lexer, char const **text,
					int *token_type, void *token_ptr[2])
{
	(void)lexer;
	(void)token_ptr;
	(void)token_type;
	*token_type = TOKEN_TIND_INT;
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
	return (TERM_UNDEFINED_CODE);
}

int					lexer_get_term_arg_ind_label(t_lexer *lexer, char const **text,
					int *token_type, void *token_ptr[2])
{
	printf("inside lexer_get_term_arg_ind_label\n");

	(void)lexer;
	if (!ft_strchr(LABEL_CHARS, **text))
	{
		*token_type = TOKEN_UNDEF;
		return (TERM_UNDEFINED_CODE);
	}
	else
	{
		token_ptr[TOKEN_START_PTR] = (void*)*text;
		*token_type = TOKEN_TIND_LAB;
		while (ft_strchr(LABEL_CHARS, **text))
			++(*text);
		token_ptr[TOKEN_END_PTR] = (void*)(*text - 1);
		printf("!!! %d\n", lexer->state);
		return (LABEL_CHARS_CODE);
	}
}
