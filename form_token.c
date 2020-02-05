//
// Created by Mudcrab Stygg on 04/02/2020.
//
#include "form_token.h"
//typedef textuct 	    s_lexer
//{
//    int             state;
//    void            *cur_token;
//    void            (*fptr_form_token)(textuct s_lexer *lexer, char **text);
//}				    t_lexer;


typedef struct 	    s_lexer
{
    int             state;
    t_token*        (*form_token)(t_lexer *lexer, char **text);
}				    t_lexer;


typedef struct 	    s_token
{
    int             tkn_type;
    void		    *tkn_begin;
    size_t		    tkn_len;
}				    t_token;



t_token*            form_token(t_lexer  *lexer, char **text);
//void                get_term(char **text, void  (*fptr_get_term_ar)(char**)[3]);
/*
 * init_state_terms
 */
void                (*fptr_init_term_switch)(char **text, void (*fptr)(char**)[4]);
void                get_term_init_state(char**text);
/*
 * 1lvl token substates
 */

void                (*fptr_1sub_term_switch)(char **text,(void) (*fptr)(char**)[2] );
void                get_term_comment_unit(char **text);
void                get_term_line_feed_unit(char **text);
void                get_term_champion_unit(char **text);
void                get_term_code_unit(char **text);
/*
 * code_state_terms
 */
void                (*fptr_code_state_term_switch)(char **text, (void) (*fptr)(char**)[2]);
void                get_term_op_name_unit(char **text);
void                get_term_label_word_unit(char **text);
/*
 * op_name_terms
 */
void                get_term_opx_name(char **text);
void                get_label_word_unitt (char **text);




void                lexer_constructor(t_lexer **lexer)
{
    if (!(*lexer = (t_lexer*)malloc(sizeof(t_lexer))))
    {
    	printf("error\n");
    	exit(-1);
    }
	(*lexer)->state = 0;
	(*lexer)->form_token = form_token;
}

void                token_constructor(t_token **token)
{
	if (!(*token = (t_token*)malloc(sizeof(t_token))))
	{
		printf("error\n");
		exit(-1);
	}
	(*token)->tkn_type = 0;
	(*token)->tkn_begin = NULL;
	(*token)->tkn_end = NULL;
	(*token)->tkn_len = 0;
}



