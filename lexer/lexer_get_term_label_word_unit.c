/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_get_term_label_word_unit.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita_toropov <nikita_toropov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:41:31 by ftothmur          #+#    #+#             */
/*   Updated: 2020/03/21 03:03:06 by nikita_toro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "lexer.h"
#include "lexer_private.h"
// #include "lexer_utils_private.h"

/*
**	The function determins if this part of text is appropriate term for
** functiom_name token.
**	INPUT:	Pointer to text after LABEL_CHARS.
**	OUTPUT:	type of term.
*/

int				lexer_get_term_label_word_unit(t_lexer *lexer, char const **text, 
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