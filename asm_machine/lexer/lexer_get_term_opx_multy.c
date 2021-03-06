/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_get_term_opx_multy.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 21:58:55 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/15 20:56:22 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_lexer.h"

static int			lexer_get_term_opx_p2(char const **text, int *type,
					void *token_ptr[2], int sign)
{
	if (ft_isdigit(**text))
	{
		*token_ptr = !(sign) ? (void*)*text : *token_ptr;
		while (ft_isdigit(**text))
			++(*text);
		token_ptr[TOKEN_TEXT_END_INDX] = (void*)(*text - 1);
		return (INTEGER_CODE);
	}
	else if (sign)
	{
		++(*text);
		*type = TOKEN_UNDEF;
		return (TERM_UNDEFINED_CODE);
	}
	if (**text == LABEL_CHAR)
	{
		(*text) += 1;
		return (LABEL_CHAR_CODE);
	}
	if (**text == DIRECT_CHAR)
	{
		(*text) += 1;
		return (DIRECT_CHAR_CODE);
	}
	return (TERM_UNDEFINED_CODE);
}

int					lexer_get_term_opx(t_lexer *lexer, char const **text,
					int *type, void *token_ptr[2])
{
	int				sign;

	sign = 0;
	(void)lexer;
	while (**text != '\0' && (ft_strchr(WHITE_SPACE, **text) || **text == '\n'))
		++(*text);
	if (**text == REGISTER_CHAR)
	{
		(*text) += 1;
		return (REGISTER_CHAR_CODE);
	}
	if ((**text == '+' || **text == '-'))
	{
		sign = **text == '+' ? 1 : -1;
		token_ptr[TOKEN_TEXT_START_INDX] = (void*)*text;
		++(*text);
	}
	return (lexer_get_term_opx_p2(text, type, token_ptr, sign));
}

static int			lexer_get_term_multi_arg_p2(char const **text, int *type,
					void *token_ptr[2], int sign)
{
	if (ft_isdigit(**text))
	{
		*token_ptr = !(sign) ? (void*)*text : *token_ptr;
		while (ft_isdigit(**text))
			++(*text);
		*(token_ptr + 1) = (void*)(*text - 1);
		return (INTEGER_CODE);
	}
	else if (sign)
	{
		++(*text);
		*type = TOKEN_UNDEF;
		return (TERM_UNDEFINED_CODE);
	}
	if (**text == LABEL_CHAR)
	{
		(*text) += 1;
		return (LABEL_CHAR_CODE);
	}
	if (**text == DIRECT_CHAR)
	{
		(*text) += 1;
		return (DIRECT_CHAR_CODE);
	}
	return (TERM_UNDEFINED_CODE);
}

int					lexer_get_term_multi_arg(t_lexer *lexer, char const **text,
					int *type, void *token_ptr[2])
{
	int				sign;

	sign = 0;
	(void)lexer;
	while (**text != '\0' && (ft_strchr(WHITE_SPACE, **text) || **text == '\n'))
		++(*text);
	if (**text == REGISTER_CHAR)
	{
		(*text) += 1;
		return (REGISTER_CHAR_CODE);
	}
	if ((**text == '+' || **text == '-'))
	{
		sign = **text == '+' ? 1 : -1;
		*token_ptr = (void*)*text;
		++(*text);
	}
	return (lexer_get_term_multi_arg_p2(text, type, token_ptr, sign));
}
