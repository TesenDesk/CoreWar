/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_get_term_comment.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita_toropov <nikita_toropov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 00:24:58 by nikita_toro       #+#    #+#             */
/*   Updated: 2020/03/13 13:10:49 by nikita_toro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "lexer.h"
#include "lexer_private.h"
// #include "token_defines.h"

/*
**	The function determins if this part of text is appropriate term for
**	comment token.
**	INPUT:	Pointer to text after COMMENT_CHAR or ALT_COMMENT_CHAR.
**	OUTPUT:	type of term.
*/

int		lexer_get_term_comment(t_lexer *lexer, char const **text, int *type, void *token_ptr[2])
{
	(void)lexer;
	(void)token_ptr;
	if (**text != '\0')
	{
		while (!(**text == '\0' || **text == '\n'))
			++(*text);
		if (**text == '\0')
		{
			return (EOF_CODE);
		}
		if (**text == '\n')
		{
			return (LINE_FEED_CODE);
		}
	}
	*type = TOKEN_UNDEF;
	return (EOF_CODE);
}
