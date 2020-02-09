/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_private.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:46:31 by ftothmur          #+#    #+#             */
/*   Updated: 2020/02/05 17:48:57 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_PRIVATE_H
#define LEXER_PRIVATE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"
/*
 * STATE MACHINE STATEs
 */

#define INIT 0
#define COMMENT 1
#define LINE_FEED 2

/*
 * champ_unit_states
*/

#define NAME_CMD 3
#define CH_NAME 4
#define COMM_CMD 5
#define CH_COMM 6

/*
 * code_unit_states
*/
#define OPX 7

/*
 * augment_unit_substates
 */

#define T_REG           8
#define T_IND           9
#define T_IND_LABEL     10
#define T_DIR_INT       11
#define T_DIR_LAB       12
#define ARG_BRK         13

/*
 * switcher_method constants
 */
////#define INIT        0
//#define GET_COMMENT 0
//#define LINE_FEED 1
////#define CHAMPION 2
//#define OPX 4
//#define LABEL_WORD 5
//#define ARG_REG 6
//#define ARG_IND_INT 7
//#define ARG_IND_LABEL 8
//#define ARG_DIR_INT 9
//#define ARG_DIR_LABEL 10
//#define ARG_BREAK 11

typedef struct 	    s_lexer
{
    int             state;
    t_token*        (*lexer_form_token)(struct s_lexer *lexer, char const **text);
    void            (*change_state)(struct s_lexer *lexer, char const **text);
    int             (*get_term[12])(struct s_lexer *lexer, char const **text, int *token_type, void *token_ptr[2]);
}				    t_lexer;

/*
 * change_state methods
 */

void                lexer_change_state(t_lexer *lexer, char const **text);

/*
 * init state methods
 */
int		lexer_get_term_init(t_lexer *lexer, char const **text, int *token_type, void *token_ptr[2]);

/*
 * 1lvl comment/feed methods
 */

int                lexer_get_term_comment(t_lexer *lexer, char const **text, int *token_type, void *token_ptr[2]);
int                lexer_get_term_line_feed(t_lexer *lexer, char const **text, int *token_type, void *token_ptr[2]);

/*
 * champion term methods
 */

int     		   lexer_get_term_name_cmd(t_lexer *lexer, char const **text, int *token_type, void *token_ptr[2]);
int    			   lexer_get_term_com_cmd(t_lexer *lexer, char const **text, int *token_type, void *token_ptr[2]);
int                lexer_get_term_ch_name(t_lexer *lexer, char const **text, int *token_type, void *token_ptr[2]);
int 			   lexer_get_term_ch_comment(t_lexer *lexer, char const **text, int *token_type, void *token_ptr[2]);

/*
 * opx/args methods
 */

int                lexer_get_term_opx(t_lexer *lexer, char const **text, int *token_type, void *token_ptr[2]);
int                lexer_get_term_label_word_unit(t_lexer *lexer, char const **text, int *token_type, void *token_ptr[2]);
int                lexer_get_term_arg_reg(t_lexer *lexer, char const **text, int *token_type, void *token_ptr[2]);
int                lexer_get_term_arg_ind_int(t_lexer *lexer, char const **text, int *token_type, void *token_ptr[2]);
int                lexer_get_term_arg_ind_label(t_lexer *lexer, char const **text, int *token_type, void *token_ptr[2]);
int                lexer_get_term_arg_dir_int(t_lexer *lexer, char const **text, int *token_type, void *token_ptr[2]);
int                lexer_get_term_arg_dir_label(t_lexer *lexer, char const **text, int *token_type, void *token_ptr[2]);
int                lexer_get_term_arg_break(t_lexer *lexer, char const **text, int *token_type, void *token_ptr[2]);


/*
 * utilities
 */


int					is_white_space(char c);
int					is_line_feed(char c);
int					is_of_label_chars(char c);


#endif