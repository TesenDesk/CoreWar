//
// Created by Mudcrab Stygg on 04/02/2020.
//

//typedef struct 	    s_lexer
//{
//    int             state;
//    void            *cur_token;
//    void            (*fptr_form_token)(struct s_lexer *lexer, char **str);
//}				    t_lexer;


typedef struct 	    s_lexer
{
    int             state;
    t_token         (*fptr_form_token)(struct s_lexer *lexer, char **str);
}				    t_lexer;


typedef struct 	    s_token
{
    int             tkn_type;
    void		    *tkn_begin;
    void		    *tkn_end;
    size_t		    tkn_len;
}				    t_token;


void                construct_lexer(t_lexer **lexer);
void                construct_token(t_token *token);

void                form_token(t_lexer  *lexer, )
void                get_term(char **str, void  (*fptr_get_term_ar)[3]);
/*
 * init_state_terms
 */
void                (*fptr_init_term_switch)(char** str, void (*fptr)[4]);
void                get_term_init_state(char**str);
/*
 * 1lvl token substates
 */

void                (*fptr_1sub_term_switch)(char** str,(void) (*fptr)[2] );
void                get_term_comment_unit(char**str);
void                get_term_line_feed_unit(char**str);
void                get_term_champion_unit(char**str);
void                get_term_code_unit(char**str);
/*
 * code_state_terms
 */
void                (*fptr_code_state_term_switch)(char** str, (void) (*fptr)[2]);
void                get_term_op_name_unit(char**str);
void                get_term_label_word_unit(char**str);
/*
 * op_name_terms
 */
void                get_term_opx_name(char**str);
void                get_term_argument_unit(char**str);




void                construct_lexer(t_lexer **lexer)
{
    if (!(*lexer = (t_lexer*)malloc(sizeof(t_lexer))))
        error();



}


