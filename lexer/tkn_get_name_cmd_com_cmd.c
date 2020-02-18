/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_get_name_cmd_com_cmd.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 19:39:17 by ftothmur          #+#    #+#             */
/*   Updated: 2020/02/11 14:41:14 by cmissy           ###   ########.fr       */
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

static void			run_through_spaces(char const **text)
{
	while (is_white_space(**text))
		++(*text);
	return ;
}

void				lexer_get_term_name_cmd(t_lexer *lexer, char const **text, int *token_type, void *token_ptr[2])
{
	while (is_white_space(*str))
		++(*str);
	if (!**text)
		token->token_type = UNDEFINED_TOKEN;
	token->token_type = CH_NAME;
	return ;
}

void				tkn_get_com_cmd(t_token *token, char const **text)
{
	while (is_white_space(*str))
		++(*str);
	if (!**text)
		token->token_type = UNDEFINED_TOKEN;
	token->token_type = CH_COMMENT;
	return ;
}