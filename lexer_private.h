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

/*
 * STATE MACHINE STATEs
 */

#define comment_unit_st 0
#define line_feed_unit_st 1

/*
 * champ_unit_states
*/

#define name_cmd_st 3
#define ch_name st 4
#define comm_cmd_st 5
#define ch_comm_st 6

/*
 * code_unit_states
*/
#define opx_name_st 7

/*
 * augment_unit_substates
 */

#define t_reg_st        8
#define t_ind_st        9
#define t_dir_int_st    10
#define t_dir_lab_st    11
#defien arg_break_st    13

/*
 * switcher_method constants
 */
//#define INIT        0
#define GET_COMMENT 0
#define LINE_FEED 1
#define CHAMPION 2
#define OPX 4
#define LABEL_WORD 5
#define OPX 6
#define ARG_REG 7
#define ARG_IND_INT 8
#define ARG_IND_LABEL 9
#define ARG_DIR_INT 10
#define ARG_DIR_LABEL 10
#define ARG_BREAK 11

typedef struct 	    s_lexer
{
    int             state;
    t_token         (*lexer_form_token)(t_lexer *lexer, char **text);
    int             (*lexer_switcher)(int (*fptr1)[12](t_lexer *lexer, char **text));
}				    t_lexer;

//int                 (*fptr_init_term_switch)(t_lexer *lexer, char **text, void (*fptr)(t_lexer *lexer,char**)[4]);
//int                lxr_get_term_init_state(t_lexer *lexer, char**text);

/*
 * 1lvl token substates
 */

//int                 (*fptr_1sub_term_switch)(t_lexer *lexer, char **text,(void) (*fptr)(t_lexer *lexer, char**)[2] );
int                lexer_get_term_comment(t_lexer *lexer, char **text);
int                lexer_get_term_line_feed(t_lexer *lexer, char **text);
int                lexer_get_term_champion(t_lexer *lexer, char **text);
//int                lexer_get_term_ch(t_lexer *lexer, char **text);
//int                lxr_get_term_code_unit(t_lexer *lexer, char **text);

/*
 * code_state_terms
 */

int                lexer_get_term_opx(t_lexer *lexer, char **text);
int                lexer_get_term_label_word_unit(t_lexer *lexer, char **text);
int                lexer_get_term_arg_reg(t_lexer *lexer, char **text);
int                lexer_get_term_arg_ind_int(t_lexer *lexer, char **text);
int                lexer_get_term_arg_ind_label(t_lexer *lexer, char **text);
int                lexer_get_term_arg_dir_int(t_lexer *lexer, char **text);
int                lexer_get_term_arg_dir_label(t_lexer *lexer, char **text);
int                lexer_get_term_arg_break(t_lexer *lexer, char **text);


/*
 * utilities
 */


int					is_white_space(char c);
int					is_line_feed(char c);
int					is_of_label_chars(char c);


#endif