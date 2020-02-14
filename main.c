#include "token.h"
#include "token_private.h"
#include "lexer.h"
#include "lexer_private.h"
#include <stdio.h>
#include "token_defines.h"

int main()
{
    t_lexer *lex;
    lexer_constructor(&lex);
    char const *str = "ld 45454, 45454, r5\n";
    t_token *token1 = lexer_form_token(lex, &str);    
    printf("token_type %i\n", token1->token_type);
    printf("str %s\n", token1->token_ptr[0]);
    
    t_token *token2 = lexer_form_token(lex, &str);    
    printf("token_type %i\n", token2->token_type);
    printf("str %s\n", token2->token_ptr[0]);

    t_token *token3 = lexer_form_token(lex, &str);    
    printf("token_type %i\n", token3->token_type);
    printf("str %s\n", token3->token_ptr[0]);

    t_token *token4 = lexer_form_token(lex, &str);    
    printf("token_type %i\n", token4->token_type);
    printf("str %s\n", token4->token_ptr[0]);



    // printf("%i\ns", token2->token_type);
    // printf("%s\n", token->token_type ==  TOKEN_TIND_INT ? "YES": "NO");

}
