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
    char const *str = "ld %45454, 45454, r5     ;blabla\n";
    t_token *token1 = lexer_form_token(lex, &str);    
    printf("token_type %i\n", token1->token_type);
    printf("str %s\n\n", token1->token_ptr[0]);
    
    t_token *token2 = lexer_form_token(lex, &str);    
    printf("token_type %i\n", token2->token_type);
    printf("token2 str %s\n\n", token2->token_ptr[0]);

    t_token *token3 = lexer_form_token(lex, &str);    
    printf("token_type %i\n", token3->token_type);
    printf("token3 str %s\n\n", token3->token_ptr[0]);

    t_token *token4 = lexer_form_token(lex, &str);    
    printf("token_type %i\n", token4->token_type);
    printf("token4 str %s\n\n", token4->token_ptr[0]);

    t_token *token5 = lexer_form_token(lex, &str);    
    printf("token_type %i\n", token5->token_type);
    printf("token5 str %s\n\n", token5->token_ptr[0]);



    // printf("%i\ns", token2->token_type);
    // printf("%s\n", token->token_type ==  TOKEN_TIND_INT ? "YES": "NO");

}
