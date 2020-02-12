#include "lexer.h"
#include "token_defines.h"
#include "lexer_private.h"

/*
**	The function determins if this part of text is appropriate term for
**	tind_integer token and set token_ptr.
**	INPUT:	Pointer to text '-', '+' or DIGIT.
**	OUTPUT:	type of term.
*/

int					lexer_get_term_arg_ind_int(t_lexer *lexer, char const **text,
					int *token_type, void *token_ptr[2])
{
	printf("inside lexer_get_term_arg_dir_int\n");
	(void)lexer;
	token_ptr[TOKEN_START_PTR] = (void*)*text;
	if (**text == '+' || **text == '-')
	{
		++(*text);
		if (!ft_isdigit(**text))
		{
			*token_type = TOKEN_UNDEF;
			return (TERM_UNDEFINED);
		}
	}
	*token_type = TOKEN_TIND_INT;
	while (ft_isdigit(**text))
		++(*text);
	token_ptr[TOKEN_END_PTR] = (void*)(*text - 1);
	return (INTEGER_CODE);
}

/*
**	The function determins if this part of text is appropriate term for
**	tind_label token and set token_ptr.
**	INPUT:	Pointer to text after LABEL_CHAR one of LABER_CHARS.
**	OUTPUT:	type of term.
*/

int					lexer_get_term_arg_ind_label(t_lexer *lexer, char const **text,
					int *token_type, void *token_ptr[2])
{
	printf("inside lexer_get_term_arg_ind_label\n");

	(void)lexer;
	if (!ft_strchr(LABEL_CHARS, **text))
	{
		*token_type = TOKEN_UNDEF;
		return (TERM_UNDEFINED);
	}
	else
	{
		token_ptr[TOKEN_START_PTR] = (void*)*text;
		*token_type = TOKEN_TIND_LAB;
		while (ft_strchr(LABEL_CHARS, **text))
			++(*text);
		token_ptr[TOKEN_END_PTR] = (void*)(*text - 1);
		return (LABEL_CHARS_CODE);
	}
}
