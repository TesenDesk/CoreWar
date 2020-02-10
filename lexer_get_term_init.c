
#include "lexer.h"
#include "lexer_private.h"

int		lexer_get_term_init(t_lexer *lexer, char const **text, int *token_type, void *token_ptr[2])
{
    while (**text == ' ' || **text == '\t')
        ++(*text);
    if (!(**text))
    {
        *token_type = TOKEN_EOF;
        return (EOF_CODE);
    }
    return (0);
}
