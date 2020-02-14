#include "lexer.h"
#include "token_defines.h"
#include "lexer_private.h"

int				lexer_get_term_arg_reg(t_lexer *lexer, char const **text,
					int *token_type, void *token_ptr[2])
{
	int			num;

	*token_type = TOKEN_TREG;
	(void)lexer;
	if (!ft_isdigit(**text) || (num = ft_atoi(*text)) < 1 || num > 16)
	{
		*token_type = TOKEN_UNDEF;
		return (TERM_UNDEFINED_CODE);
	}
	token_ptr[TOKEN_START_PTR] = (void*)(*text);
	while (ft_isdigit(**text))
		++(*text);
	token_ptr[TOKEN_END_PTR] = (void*)(*text - 1);
	return (INTEGER_CODE);
}