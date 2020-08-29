/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_get_term_ch_comment.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:14:39 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/29 19:01:03 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    long long   counter;

	(void)lexer;
	token_ptr[TOKEN_START_PTR] = (void *)*text;
	counter = lexer_utils_trim_not_eof_not_line_feed_not_quotatuion_mark(text);
	if (counter > 2048)
    {
	    ft_printf("Champion comment too long (Max length 2048)\n");
	    exit(-1);
    }
	if (lexer_utils_is_quotation_mark(**text))
	{
		*type = TOKEN_CHCOM;
		token_ptr[TOKEN_END_PTR] = (void *)(*text - 1);
		++(*text);
		return (QUOTATION_MARK_CODE);
	}
	return (TERM_UNDEFINED_CODE);
}
