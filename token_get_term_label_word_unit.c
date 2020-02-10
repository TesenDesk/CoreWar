/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_get_term_label_word_unit.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:41:31 by ftothmur          #+#    #+#             */
/*   Updated: 2020/02/10 19:22:04 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "lexer_private.h"
#include "lexer_utils.h"


// #define TERM_UNDEFINED          -1
// #define COMMENT_CHAR_CODE		1
// #define ALT_COMMENT_CHAR_CODE   2

// #define REGISTER_CHAR_CODE      3
// #define LABEL_CHAR_CODE         4
// #define DIRECT_CHAR_CODE        5

// #define SEPARATOR_CHAR_CODE     6

// #define LABEL_CHARS_CODE			7
// #define NAME_CMD_STRING_CODE		8
// #define COMMENT_CMD_STRING_CODE	9
// #define WHITE_SPACE_CODE			10


// #define ADD_NAME_CODE			11
// #define AFF_NAME_CODE			12
// #define AND_NAME_CODE			13
// #define FORK_NAME_CODE		    14
// #define LD_NAME_CODE				15
// #define LDI_NAME_CODE		    16
// #define LFORK_NAME_CODE		    17
// #define LIVE_NAME_CODE		    18
// #define LLD_NAME_CODE		    19
// #define LLDI_NAME_CODE			20
// #define OR_NAME_CODE				21
// #define ST_NAME_CODE				22
// #define STI_NAME_CODE		    23
// #define SUB_NAME_CODE	        24
// #define XOR_NAME_CODE			25
// #define ZJMP_NAME_CODE			26

// #define QUOTATION_MARK_CODE		27

/*
**	The function determins if this part of text is appropriate term for
** functiom_name token.
**	INPUT:	Pointer to text after LABEL_CHARS.
**	OUTPUT:	type of term.
*/

int				lexer_get_term_label_word(t_lexer *lexer, char const **text, 
				int *token_type, void *token_ptr[2])
{
	if (lexer_utils_is_label_char(**text))
	{
		*token_type = LABEL_WORD;
		return (LABEL_CHAR_CODE);
	}
	*token_type = TOKEN_UNDEF;
	return (TERM_UNDEFINED);
}