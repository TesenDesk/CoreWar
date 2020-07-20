/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_defines.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 21:07:15 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/14 21:09:07 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_DEFINES_H
# define TOKEN_DEFINES_H

enum			e_token_types
{
	NO_TOKEN = -1,
	TOKEN_LFEED,
	TOKEN_LABEL_WORD,
	TOKEN_CHNAME,
	TOKEN_CHCOM,
	TOKEN_AFF,
	TOKEN_ST,
	TOKEN_STI,
	TOKEN_ADD,
	TOKEN_SUB,
	TOKEN_LD,
	TOKEN_LLD,
	TOKEN_LDI,
	TOKEN_LLDI,
	TOKEN_AND,
	TOKEN_OR,
	TOKEN_XOR,
	TOKEN_LIVE,
	TOKEN_ZJMP,
	TOKEN_FORK,
	TOKEN_LFORK,
	TOKEN_TREG,
	TOKEN_TIND_INT,
	TOKEN_TIND_LAB,
	TOKEN_TDIR_INT,
	TOKEN_TDIR_LAB,
	TOKEN_UNDEF,
	TOKEN_INIT_ST,
	TOKEN_EOF,
	NUM_OF_TOKENS,
};

# define COMMENT_CHAR			'#'
# define ALT_COMMENT_CHAR		';'

# define REGISTER_CHAR			'r'
# define LABEL_CHAR				':'
# define DIRECT_CHAR				'%'

# define SEPARATOR_CHAR			','
# define LINE_FEED				'\n'

# define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"
# define NAME_CMD_STRING			".name"
# define COMMENT_CMD_STRING		".comment"
# define WHITE_SPACE				" \t"

# define ADD_NAME				"add"
# define AFF_NAME				"aff"
# define AND_NAME				"and"
# define FORK_NAME				"fork"
# define LD_NAME					"ld"
# define LDI_NAME				"ldi"
# define LFORK_NAME				"lfork"
# define LIVE_NAME				"live"
# define LLD_NAME				"lld"
# define LLDI_NAME				"lldi"
# define OR_NAME					"or"
# define ST_NAME					"st"
# define STI_NAME				"sti"
# define SUB_NAME				"sub"
# define XOR_NAME				"xor"
# define ZJMP_NAME				"zjmp"

# define QUOTATION_MARK			'\"'

enum							e_term_codes
{
	TERM_UNDEFINED_CODE = -1,
	INTEGER_CODE,
	COMMENT_CHAR_CODE,
	ALT_COMMENT_CHAR_CODE,
	REGISTER_CHAR_CODE,
	LABEL_CHAR_CODE,
	DIRECT_CHAR_CODE,
	SEPARATOR_CHAR_CODE,
	LABEL_CHARS_CODE,
	NAME_CMD_STRING_CODE,
	COMMENT_CMD_STRING_CODE,
	WHITE_SPACE_CODE,
	ADD_NAME_CODE,
	AFF_NAME_CODE,
	AND_NAME_CODE,
	FORK_NAME_CODE,
	LD_NAME_CODE,
	LDI_NAME_CODE,
	LFORK_NAME_CODE,
	LIVE_NAME_CODE,
	LLD_NAME_CODE,
	LLDI_NAME_CODE,
	OR_NAME_CODE,
	ST_NAME_CODE,
	STI_NAME_CODE,
	SUB_NAME_CODE,
	XOR_NAME_CODE,
	ZJMP_NAME_CODE,
	OPX_CODE,
	QUOTATION_MARK_CODE,
	LINE_FEED_CODE,
	EOF_CODE,
};

#endif
