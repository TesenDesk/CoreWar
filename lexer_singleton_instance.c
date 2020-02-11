#include "lexer.h"
#include "lexer_private.h"

t_lexer				*lexer_singleton_instance()
{
	static t_lexer	*lexer_instance;

	if (!instance)
		_lexer_constructor(&lexer_instance);
	return (lexer_instance);
}
