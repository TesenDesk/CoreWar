/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_get_term_label_word_unit.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:41:31 by ftothmur          #+#    #+#             */
/*   Updated: 2020/02/18 19:53:52 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "lexer_private.h"
#include "lexer_utils_private.h"

/*
**	The function determins if this part of text is appropriate term for
** functiom_name token.
**	INPUT:	Pointer to text after LABEL_CHARS.
**	OUTPUT:	type of term.
*/

int				lexer_get_term_label_word(t_lexer *lexer, char const **text, 
				int *type, void *token_ptr[2])
{
	(void)lexer;
	(void)token_ptr;
	if (lexer_utils_is_label_char(**text))
	{
		*type = TOKEN_LABEL_WORD;
		++(*text);
		return (LABEL_CHAR_CODE);
	}
	*type = TOKEN_UNDEF;
	return (TERM_UNDEFINED_CODE);
}