/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_get_term_comment.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 00:24:58 by nikita_toro       #+#    #+#             */
/*   Updated: 2020/02/12 18:11:02 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "lexer_private.h"
#include "token_defines.h"

/*
**	The function determins if this part of text is appropriate term for
**	comment token.
**	INPUT:	Pointer to text after COMMENT_CHAR or ALT_COMMENT_CHAR.
**	OUTPUT:	type of term.
*/

int		lexer_get_term_comment(t_lexer *lexer, char const **text, int *token_type, void *token_ptr[2])
{
	(void)lexer;
	(void)token_ptr;
	if (**text != '\0')
	{
		while (!(**text == '\0' || **text == '\n'))
			++(*text);
		if (**text == '\0')
		{
			*token_type = TOKEN_UNDEF;
			return (EOF_CODE);
		}
		if (**text == '\n')
		{
			*token_type = LINE_FEED;
			return (LINE_FEED_CODE);
		}
	}
	*token_type = TOKEN_UNDEF;
	return (EOF_CODE);
}
