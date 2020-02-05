//
// Created by Mudcrab Stygg on 04/02/2020.
//

//typedef textuct 	    s_lexer
//{
//    int             state;
//    void            *cur_token;
//    void            (*fptr_form_token)(textuct s_lexer *lexer, char **text);
//}				    t_lexer;

#include <stdio.h>
#include <stdlib.h>


typedef             struct s_lexer t_lexer;
typedef             struct s_token t_token;

t_token*            form_token(t_lexer  *lexer, char **text);
/*
 * init_state_terms
 */
void                (*fptr_init_term_switch)(t_token *token, char **text, void (*fptr)(t_token *token,char**)[4]);
void                tkn_get_term_init_state(t_token *token, char**text);

/*
 * 1lvl token substates
 */

void                (*fptr_1sub_term_switch)(t_token *token, char **text,(void) (*fptr)(t_token *token, char**)[2] );
void                tkn_get_term_comment_unit(t_token *token, char **text);
void                tkn_get_term_line_feed_unit(t_token *token, char **text);
void                tkn_get_term_champion_unit(t_token *token, char **text);
void                tkn_get_term_code_unit(t_token *token, char **text);
/*
 * code_state_terms
 */
void                (*fptr_code_state_term_switch)(t_token *token, char **text, (void) (*fptr)(char**)[2]);
void                tkn_get_term_op_name_unit(t_token *token, char **text);
void                tkn_get_term_label_word_unit(t_token *token, char **text);
/*
 * op_name_terms
 */
void                tkn_get_term_opx_name(t_token *token, char **text);
void                tkn_get_label_word_unitt (t_token *token, char **text);



