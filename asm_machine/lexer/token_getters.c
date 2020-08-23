/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_getters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 20:16:34 by cmissy            #+#    #+#             */
/*   Updated: 2020/08/23 14:48:19 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_token.h"

void				token_destructor(t_token **token)
{
	if (token)
	{
		if (*token)
		{
			free((*token)->val);
			(*token)->val = NULL;
			(*token)->token_ptr[0] = NULL;
			(*token)->token_ptr[1] = NULL;
		}
		free(*token);
		*token = NULL;
	}
}

int					token_get_type(t_token *token)
{
	if (token)
		return (token->type);
	return (NO_TOKEN);
}

void				*token_get_value(t_token *token)
{
	if (token)
		return (token->val);
	return (NULL);
}

void				*get_begin(t_token *token)
{
	return (token->token_ptr[0]);
}

void				*token_get_token_ptr(t_token *token, int index)
{
	return (token->token_ptr[index]);
}
