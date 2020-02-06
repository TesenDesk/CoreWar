/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_get_comment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita_toropov <nikita_toropov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 00:24:58 by nikita_toro       #+#    #+#             */
/*   Updated: 2020/02/06 18:04:37 by nikita_toro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

void		tkn_get_comment(t_token *token, const char **text)
{
	if (!**text)
		token->token_type = UNDEFINED_TOKEN;
	while (!**text && **text != '\n')
		++(*text);
	return ;
}
