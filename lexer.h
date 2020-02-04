/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:35:16 by ftothmur          #+#    #+#             */
/*   Updated: 2020/02/04 18:29:51 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
#define LEXER_H

#define COMMENT_CHAR			'#'
#define ALT_COMMENT_CHAR		';'

#define REGISTER_CHAR           'r'
#define LABEL_CHAR				':'
#define DIRECT_CHAR				'%'

#define SEPARATOR_CHAR			','

#define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"
#define NAME_CMD_STRING			".name"
#define COMMENT_CMD_STRING		".comment"
#define WHITE_SPACE				" \t"

/*
** Operation names.
*/
#define ADD_NAME				"add"
#define AFF_NAME				"aff"
#define AND_NAME				"and"
#define FORK_NAME				"fork"
#define LD_NAME					"ld"
#define LDI_NAME				"ldi"
#define LFORK_NAME				"lfork"
#define LIVE_NAME				"live"
#define LLD_NAME				"lld"
#define LLDI_NAME				"lldi"
#define OR_NAME					"or"
#define ST_NAME					"st"
#define STI_NAME				"sti"
#define SUB_NAME				"sub"
#define XOR_NAME				"xor"
#define ZJMP_NAME				"zjmp"

#define QUOTATION_MARK			'\"'

enum							e_words
{
	UNDEFINED_TOKEN = -1,
	EOF_WORD,
	LINE_FEED,
	CH_NAME,
	CH_COMMENT,
	LABEL_WORD,
	OP_NAME,
	T_REG,
	T_IND,
	T_DIR
};

/*
** The attribute structure with no disclosed attribute.
*/
struct                          s_lexer;
typedef struct s_lexer          t_lexer;

/*
** Constructor and destructor functions.
*/
void			lexer_ctor(t_lexer *lexer);
void			lexer_dtor(t_lexer *lexer);

/*
** Public behavioral functions.
*/
int				lexer_get_token_id(t_lexer *lexer);
char			*lexer_get_token_str(t_lexer *lexer);

/*
** Inner tokenizing functions
*/
int             lexer_switcher(char *str);

#endif