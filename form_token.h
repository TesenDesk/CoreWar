//
// Created by Mudcrab Stygg on 04/02/2020.
//

typedef struct 	    s_lexer t_lexer;
typedef struct 	    s_token t_token;


void                construct_lexer(t_lexer **lexer);
void                construct_token(t_token *token);

void                form_token(t_lexer  *lexer, )
void                get_term(void * (*fptr_get_term_ar)[7]);
/*
 * init_state_terms
 */
void                get_term_init_state(char**str);
/*
 * 1lvl token substates
 */
void                get_term_comment_unit(char**str);
void                get_term_line_feed_unit(char**str);
void                get_term_champion_unit(char**str);
void                get_term_code_unit(char**str);
/*
 * code_state_terms
 */
void                get_term_op_name_unit(char**str);
void                get_term_label_word_unit(char**str);
/*
 * op_name_terms
 */
void                get_term_opx_name(char**str);
void                get_term_argument_unit(char **str);


