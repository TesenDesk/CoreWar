#include "token.h"
#include "token_private.h"
#include "lexer.h"
#include <stdio.h>

int main()
{
    t_lexer *lex;
    lexer_constructor(&lex);
    char const *str = "     #\n";
    printf("sasas\n");
    t_token *token = lexer_form_token(lex, &str);
    printf("sasas\n");
    printf("%d\n", token->token_type);

}
