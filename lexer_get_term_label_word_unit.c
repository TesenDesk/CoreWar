/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_get_term_label_word_unit.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:41:31 by ftothmur          #+#    #+#             */
<<<<<<< HEAD:tkn_get_term_label_word_unit.c
/*   Updated: 2020/02/10 19:38:06 by cmissy           ###   ########.fr       */
=======
/*   Updated: 2020/02/10 20:31:08 by ftothmur         ###   ########.fr       */
>>>>>>> 43073a5d83d33d9c85cdc87e695a204330ec7eba:lexer_get_term_label_word_unit.c
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "lexer_private.h"
#include "lexer_utils.h"

/*
**	The function determins if this part of text is appropriate term for
** functiom_name token.
**	INPUT:	Pointer to text after LABEL_CHARS.
**	OUTPUT:	type of term.
*/

int				lexer_get_term_label_word(t_lexer *lexer, char const **text, 
				int *token_type, void *token_ptr[2])
{
	(void)lexer;
	(void)token_ptr;
	if (lexer_utils_is_label_char(**text))
	{
<<<<<<< HEAD:tkn_get_term_label_word_unit.c
		token->token_type = UNDEFINED_TOKEN;
=======
		*token_type = LABEL_WORD;
		++(*text);
		return (LABEL_CHAR_CODE);
>>>>>>> 43073a5d83d33d9c85cdc87e695a204330ec7eba:lexer_get_term_label_word_unit.c
	}
	*token_type = TOKEN_UNDEF;
	return (TERM_UNDEFINED);
}