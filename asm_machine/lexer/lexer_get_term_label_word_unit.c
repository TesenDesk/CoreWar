/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_get_term_label_word_unit.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:41:31 by ftothmur          #+#    #+#             */
/*   Updated: 2020/07/14 21:57:47 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_lexer.h"

int			lexer_get_term_label_word_unit(t_lexer *lexer, char const **text,
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
