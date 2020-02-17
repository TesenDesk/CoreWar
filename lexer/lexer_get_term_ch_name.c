/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_get_term_ch_name.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:13:53 by ftothmur          #+#    #+#             */
/*   Updated: 2020/02/12 21:41:10 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "lexer_private.h"
#include "lexer_utils_private.h"
#include "token_defines.h"

/*
**	The function determins if this part of text is appropriate term for
** functiom_name token.
**	INPUT:	Pointer to text after NAME_CMD_STRING.
**	OUTPUT:	type of term.
*/

int				lexer_get_term_ch_name(t_lexer *lexer, char const **text, 
				int *token_type, void *token_ptr[2])
{
	(void)lexer;
	token_ptr[TOKEN_START_PTR] = *text;
	lexer_utils_trim_not_eof_not_line_feed_not_quotatuion_mark(text);
	if (lexer_utils_is_quotation_mark(**text))
	{
		*token_type = TOKEN_CHNAME;
		token_ptr[TOKEN_END_PTR] = *(text - 1);
		++(*text);
		return (QUOTATION_MARK_CODE);
	}
	return (TERM_UNDEFINED_CODE);
}