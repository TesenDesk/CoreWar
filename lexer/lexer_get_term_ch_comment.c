/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_get_term_ch_comment.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:14:39 by ftothmur          #+#    #+#             */
/*   Updated: 2020/03/06 21:21:05 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "lexer.h"
// #include "token_defines.h"
#include "prvt_lexer.h"

/*
**	The function determins if this part of text is appropriate term for
** functiom_name token.
**	INPUT:	Pointer to text after COMMENT_CMD_STRING.
**	OUTPUT:	type of term.
*/

int				lexer_get_term_ch_comment(t_lexer *lexer, char const **text, 
				int *type, void *token_ptr[2])
{
	(void)lexer;
	token_ptr[TOKEN_START_PTR] = (void *)*text;
	lexer_utils_trim_not_eof_not_line_feed_not_quotatuion_mark(text);
	if (lexer_utils_is_quotation_mark(**text))
	{
		*type = TOKEN_CHCOM;
		token_ptr[TOKEN_END_PTR] = (void *)(*text - 1);
		++(*text);
		return (QUOTATION_MARK_CODE);
	}
	return (TERM_UNDEFINED_CODE);
}