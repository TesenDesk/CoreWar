#include "token.h"
#include "token_private.h"
#include "lexer.h"
#include <stdio.h>
#include "token_defines.h"

int main()
{
    t_lexer *lex;
    lexer_constructor(&lex);
    char const *str = "+45454\n";
    t_token *token = lexer_form_token(lex, &str);

    printf("%i\n", token->token_type);
    printf("%s\n", token->token_type ==  TOKEN_TIND_INT ? "YES": "NO");

}
