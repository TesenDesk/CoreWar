//
// Created by Mudcrab Stygg on 04/02/2020.
//

typedef struct 	    s_lexer
{
    int             state;
    void            *cur_token;
    void            (*fptr_form_token)(struct s_lexer *lexer, char **str);
}				    t_lexer;


typedef struct 	    s_token
{
    int             token_type;
    void		    *tkn_begin;
    void		    *tkn_end;
    size_t		    tkn_len;
}				    t_token;


typedef struct 	    s_lexer
{
    int             state;
    t_token         (*fptr_form_token)(struct s_lexer *lexer, char **str);
}				    t_lexer;


void                construct_lexer(t_lexer *lexer);
void                construct_token(t_token *token);

void                form_token(t_lexer  *lexer, )
void                get_term(void * (*fptr_get_term_ar)[7]);


