/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_get_name_cmd_com_cmd.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 19:39:17 by ftothmur          #+#    #+#             */
/*   Updated: 2020/02/06 17:59:18 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "token_private.h"

#define SUCCESS		0
#define FAILURE		(-1)

int					tkn_is_white_space(char c)
{
	int			result;

	result = (c == '\t' || c == ' ');
	return (result);
}

static void			run_through_spaces(const char **text)
{
	while (is_white_space(**text))
		++(*text);
	return ;
}

void				tkn_get_name_cmd(t_token *token, const char **text)
{
	while (is_white_space(*str))
		++(*str);
	if (!**text)
		token->token_type = UNDEFINED_TOKEN;
	token->token_type = CH_NAME;
	return ;
}

void				tkn_get_com_cmd(t_token *token, const char **text)
{
	while (is_white_space(*str))
		++(*str);
	if (!**text)
		token->token_type = UNDEFINED_TOKEN;
	token->token_type = CH_COMMENT;
	return ;
}