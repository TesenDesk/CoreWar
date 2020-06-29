/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_private.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita_toropov <nikita_toropov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:46:31 by ftothmur          #+#    #+#             */
/*   Updated: 2020/03/21 03:01:27 by nikita_toro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_PRIVATE_H
#define LEXER_PRIVATE_H

#include "lexer.h"
#include "lexer_utils_private.h"
#include "token.h"
#include "token_defines.h"

#define TOKEN_START_PTR	0
#define TOKEN_END_PTR	1

/*
**	______lexer states______
**	STATE MACHINE:	INIT_ST, COMMENT_ST, LINE_FEED_ST
**	CHAMP_UNIT:		NAME_CMD_ST, CH_NAME_ST, COMM_CMD_ST, CH_COMM_ST
**	CODE_UNIT:		OPX_ST
**	EOF_ST:			EOF_ST
**	augment_unit_substates:	T_REG_ST, ARG_BRK_ST, MULTI_ARG_ST,
**							T_IND_INT_ST, T_IND_LABEL_ST,
**							T_DIR_INT_ST, T_DIR_LAB_ST,
*/

enum				e_lexer_states
{
	INIT_ST,
	COMMENT_ST,
	LINE_FEED_ST,
	NAME_CMD_ST,
	CH_NAME_ST,
	COMM_CMD_ST,
	CH_COMM_ST,
	OPX_ST,
	EOF_ST,
	T_REG_ST,
	T_IND_INT_ST,
	T_IND_LABEL_ST,
	T_DIR_INT_ST,
	T_DIR_LAB_ST,
	ARG_BRK_ST,
	MULTI_ARG_ST,
	LABEL_WORD_ST
};

/*
**	______switcher_method constants______
*/

// enum				e_switcher_method_constants
// {
// ////	INIT_ST,
// //	GET_COMMENT,
// //	LINE_FEED,
// ////	CHAMPION,
// 	OPX,
// //	LABEL_WORD,
// //	ARG_REG,
// 	ARG_IND_INT,
// 	ARG_IND_LABEL,
// //	ARG_DIR_INT,
// //	ARG_DIR_LABEL,
// 	ARG_BREAK,
// };


// /*
//  * STATE MACHINE STATEs
//  */

// #define INIT_ST 0
// #define COMMENT_ST 1
// #define LINE_FEED_ST 2

// /*
//  * CHAMP_UNIT STATES
// */

// #define NAME_CMD_ST 3
// #define CH_NAME_ST 4
// #define COMM_CMD_ST 5
// #define CH_COMM_ST 6

// /*
//  * CODE_UNIT STATES
// */
// #define OPX_ST 7

// /*
//  * EOF_ST
//  */
// #define EOF_ST 8
// /*
//  * augment_unit_substates
//  */

// #define T_REG_ST           8
// #define T_IND_INT_ST       9
// #define T_IND_LABEL_ST     10
// #define T_DIR_INT_ST       11
// #define T_DIR_LAB_ST       12
// #define ARG_BRK_ST         13
// #define MULTI_ARG_ST       14

// /*
//  * switcher_method constants
//  */
// ////#define INIT_ST        0
// //#define GET_COMMENT 0
// //#define LINE_FEED 1
// ////#define CHAMPION 2
// #define OPX 4
// //#define LABEL_WORD 5
// //#define ARG_REG 6
// #define ARG_IND_INT 7
// #define ARG_IND_LABEL 8
// //#define ARG_DIR_INT 9
// //#define ARG_DIR_LABEL 10
// #define ARG_BREAK 11

typedef struct		s_lexer
{
	int		state;
	t_token			*(*lexer_form_token)(struct s_lexer *lexer,
						char const **text);
	void			(*change_state)(struct s_lexer *lexer, int term_type);
	int				(*get_term[20])(struct s_lexer *lexer, char const **text,
						int *type, void *token_ptr[2]);
}					t_lexer;

/*
** change_state methods
*/

void				lexer_change_state(t_lexer *lexer, int term_type);

/*
** INIT_ST state methods
*/
int					lexer_get_term_init(t_lexer *lexer, char const **text,
						int *type, void *token_ptr[2]);

/*
** 1lvl comment/feed methods
*/

int					lexer_get_term_comment(t_lexer *lexer, char const **text,
						int *type, void *token_ptr[2]);
int					lexer_get_term_line_feed(t_lexer *lexer, char const **text,
						int *type, void *token_ptr[2]);

/*
** champion term methods
*/

int					lexer_get_term_name_cmd(t_lexer *lexer, char const **text,
						int *type, void *token_ptr[2]);
int					lexer_get_term_com_cmd(t_lexer *lexer, char const **text,
						int *type, void *token_ptr[2]);
int					lexer_get_term_ch_name(t_lexer *lexer, char const **text,
						int *type, void *token_ptr[2]);
int 				lexer_get_term_ch_comment(t_lexer *lexer, char const **text,
						int *type, void *token_ptr[2]);

/*
** opx args methods
*/

int					lexer_get_term_opx(t_lexer *lexer, char const **text,
						int *type, void *token_ptr[2]);
int					lexer_get_term_label_word_unit(t_lexer *lexer,
						char const **text, int *type, void *token_ptr[2]);
int					lexer_get_term_arg_reg(t_lexer *lexer, char const **text,
						int *type, void *token_ptr[2]);
int					lexer_get_term_arg_ind_int(t_lexer *lexer,
						char const **text, int *type, void *token_ptr[2]);
int					lexer_get_term_arg_ind_label(t_lexer *lexer,
						char const **text, int *type, void *token_ptr[2]);
int					lexer_get_term_arg_dir_int(t_lexer *lexer,
						char const **text, int *type, void *token_ptr[2]);
int					lexer_get_term_arg_dir_label(t_lexer *lexer,
						char const **text, int *type, void *token_ptr[2]);
int					lexer_get_term_arg_break(t_lexer *lexer, char const **text,
						int *type, void *token_ptr[2]);
int					lexer_get_term_multi_arg(t_lexer *lexer, char const **text,
						int *type, void *token_ptr[2]);

#endif