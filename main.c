#include "lexer/lexer.h"
#include "lexer/lexer_private.h"
#include "lexer/lexer_utils_private.h"
#include <stdio.h>
#include "lexer/token.h"
#include "lexer/token_defines.h"
#include "lexer/token_private.h"


int main()
{
    t_lexer *lex;
//   _lexer_constructor(&lex);
//    lex = lexer_is
    lex = lexer_singleton_instance(LEXER_INSTANTIATE);
    char const *str = "ld 45454, %:marker, r5     ;blabla\n";
    t_token *token1 = lexer_form_token(lex, &str);    
    printf("type %i\n", token1->type);
    printf("str %s\n\n", token1->token_ptr[0]);
    
    t_token *token2 = lexer_form_token(lex, &str);    
    printf("type %i\n", token2->type);
    printf("token2 str %s\n\n", token2->token_ptr[0]);

    t_token *token3 = lexer_form_token(lex, &str);    
    printf("type %i\n", token3->type);
    printf("token3 str %s\n\n", token3->token_ptr[0]);

    t_token *token4 = lexer_form_token(lex, &str);    
    printf("type %i\n", token4->type);
    printf("token4 str %s\n\n", token4->token_ptr[0]);

    t_token *token5 = lexer_form_token(lex, &str);    
    printf("type %i\n", token5->type);
    printf("token5 str %s\n\n", token5->token_ptr[0]);



    // printf("%i\ns", token2->type);
    // printf("%s\n", token->type ==  TOKEN_TIND_INT ? "YES": "NO");

}
