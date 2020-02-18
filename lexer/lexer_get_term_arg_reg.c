#include "lexer.h"
#include "token_defines.h"
#include "lexer_private.h"

int				lexer_get_term_arg_reg(t_lexer *lexer, char const **text,
					int *type, void *token_ptr[2])
{
	int			num;

	*type = TOKEN_TREG;
	(void)lexer;
	if (!ft_isdigit(**text) || (num = ft_atoi(*text)) < 1 || num > 16)
	{
		*type = TOKEN_UNDEF;


		return (TERM_UNDEFINED_CODE);
	}
	token_ptr[TOKEN_START_PTR] = (void*)(*text);
	while (ft_isdigit(**text))
		++(*text);
	token_ptr[TOKEN_END_PTR] = (void*)(*text - 1);
	return (INTEGER_CODE);
}