/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_private.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:46:31 by ftothmur          #+#    #+#             */
/*   Updated: 2020/02/10 20:42:40 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_PRIVATE_H
#define LEXER_PRIVATE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"

#define TOKEN_START_PTR	0
#define TOKEN_END_PTR	1

/*
 * STATE MACHINE STATEs
 */

#define INIT_ST 0
#define COMMENT_ST 1
#define LINE_FEED_ST 2

/*
 * CHAMP_UNIT STATES
*/

#define NAME_CMD_ST 3
#define CH_NAME_ST 4
#define COMM_CMD_ST 5
#define CH_COMM_ST 6

/*
 * CODE_UNIT STATES
*/
#define OPX_ST 7

/*
 * augment_unit_substates
 */

#define T_REG_ST           8
#define T_IND_INT_ST       9
#define T_IND_LABEL_ST     10
#define T_DIR_INT_ST       11
#define T_DIR_LAB_ST       12
#define ARG_BRK_ST         13
#define MULTI_ARG_ST       14

/*
 * switcher_method constants
 */
////#define INIT_ST        0
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
	void            (*change_state)(struct s_lexer *lexer, int term_type);
	int             (*get_term[12])(struct s_lexer *lexer, char const **text, int *token_type, void *token_ptr[2]);
}				    t_lexer;

/*
 * change_state methods
 */

void                lexer_change_state(t_lexer *lexer, int term_type);

/*
 * INIT_ST state methods
 */
int		            lexer_get_term_init(t_lexer *lexer, char const **text, int *token_type, void *token_ptr[2]);

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