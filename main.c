#include "token.h"
#include "token_private.h"
#include "lexer.h"
#include <stdio.h>
#include "token_defines.h"

int main()
{
    t_lexer *lex;
    lexer_constructor(&lex);
    char const *str = ".name\"ab\"";
    t_token *token = lexer_form_token(lex, &str);
    printf("%s\n", token->token_type ==  TOKEN_CHNAME ? "YES": "NO");
}
