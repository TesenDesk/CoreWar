/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_get_name_cmd_com_cmd.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:ch_name_ch_comment_func.c
/*   Created: 2020/02/04 16:51:57 by ftothmur          #+#    #+#             */
/*   Updated: 2020/02/05 18:55:45 by cmissy           ###   ########.fr       */
=======
/*   Created: 2020/02/05 19:39:17 by ftothmur          #+#    #+#             */
/*   Updated: 2020/02/05 19:40:12 by ftothmur         ###   ########.fr       */
>>>>>>> 7e4ecc40a260cfb339a0a83c53971cfb4862d4cc:tkn_get_name_cmd_com_cmd.c
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "token_private.h"

#define SUCCESS		0
#define FAILURE		(-1)

static int			is_white_space(char c)
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