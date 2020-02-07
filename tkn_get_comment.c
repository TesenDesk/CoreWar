/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_get_comment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 00:24:58 by nikita_toro       #+#    #+#             */
/*   Updated: 2020/02/07 11:45:26 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void		tkn_get_comment(t_token *token, const char **text)
{
	*text += 1;
	if (**text == '\n' || **text == '\0')
		token->token_type = UNDEFINED_TOKEN;
	while (!**text && **text != '\n')
		++(*text);
	return ;
}