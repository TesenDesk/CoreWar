/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_lexer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:46:31 by ftothmur          #+#    #+#             */
/*   Updated: 2020/07/14 21:45:45 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRVT_LEXER_H
# define PRVT_LEXER_H


# include "lexer.h"
# include "prvt_lexer_utils.h"

# define TOKEN_START_PTR	0
# define TOKEN_END_PTR		1

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

typedef struct		s_lexer
{
	int				state;
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
int					lexer_get_term_ch_comment(t_lexer *lexer, char const **text,
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
