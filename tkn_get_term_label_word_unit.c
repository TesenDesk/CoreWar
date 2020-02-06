/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_get_term_label_word_unit.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:41:31 by ftothmur          #+#    #+#             */
/*   Updated: 2020/02/06 17:27:54 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "token_private.h"

#define SUCCESS		0
#define FAILURE		(-1)

int						is_underscore(char c)
{
	return (c == '_');
}

int						is_line_feed(char c)
{
	return (c == '\n');
}

int						is_of_label_chars(char c)
{
	return (ft_strchr(LABEL_CHARS, c) != NULL)
}

void					tkn_get_term_label_word_unit
						(t_token *token, const char **text)
{
	token->tkn_begin = *text;
	while (is_of_label_chars(**text))
		++(*text);
	if (is_line_feed(**text))
	{
		token->tkn_len = *text - token->tkn_beging;
		token->token_type = LABEL_WORD;
	}
	else
	{
		token->token_type = UNDEFINED_TOKEN;	
	}
	return ;
}