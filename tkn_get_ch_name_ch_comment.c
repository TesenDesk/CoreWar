/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_get_ch_name_ch_comment.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:51:57 by ftothmur          #+#    #+#             */
/*   Updated: 2020/02/05 19:40:09 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "token_private.h"

#define SUCCESS		0
#define FAILURE		(-1)

static int			mark_out_token(t_token *token, const char *text, char *end)
{
	while (is_white_space(**text))
		++(*text);
	if (**text == QUOTATION_MARK)
		++(*text);
	else
	{
		token->token_type = UNDEFINED_TOKEN;
		return (FAILURE);
	}
	token->tkn_begin = *text;
	if (!(end = ft_strchr(text, QUOTATION_MARK)))
	{
		token->token_type = UNDEFINED_TOKEN;
		return (FAILURE);
	}	
	token->tkn_len = end - text;
	return (SUCCESS);
}

void				tkn_get_ch_name(t_token *token, const char **text)
{
	if (mark_out_token(token, text) == FAILURE)
		return ;
	return ;
}

void				tkn_get_ch_comment(t_token *token, const char **text)
{
	if (mark_out_token(token, text) == FAILURE)
		return ;
	return ;
}