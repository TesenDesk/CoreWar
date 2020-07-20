/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_get_term_arg_ind.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 21:56:44 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/14 21:56:56 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_lexer.h"

int				lexer_get_term_arg_ind_int(t_lexer *lexer, char const **text,
					int *type, void *token_ptr[2])
{
	(void)lexer;
	(void)token_ptr;
	(void)type;
	*type = TOKEN_TIND_INT;
	if (**text == SEPARATOR_CHAR)
	{
		++(*text);
		return (SEPARATOR_CHAR_CODE);
	}
	return (TERM_UNDEFINED_CODE);
}

int				lexer_get_term_arg_ind_label(t_lexer *lexer, char const **text,
					int *type, void *token_ptr[2])
{
	(void)lexer;
	if (!ft_strchr(LABEL_CHARS, **text))
	{
		*type = TOKEN_UNDEF;
		return (TERM_UNDEFINED_CODE);
	}
	token_ptr[TOKEN_START_PTR] = (void*)*text;
	*type = TOKEN_TIND_LAB;
	while (ft_strchr(LABEL_CHARS, **text))
		++(*text);
	token_ptr[TOKEN_END_PTR] = (void*)(*text - 1);
	return (LABEL_CHARS_CODE);
}
