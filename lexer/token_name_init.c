/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_name_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 20:25:30 by ftothmur          #+#    #+#             */
/*   Updated: 2020/03/05 21:06:33 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "token_private.h"
#include "token_defines.h"

int				token_name_init(t_token *t)
{
	char		*token_name;

	if (!(token_name = ft_strsub((char *)(t->token_ptr[TOKEN_TEXT_START_INDX]),
			TOKEN_TEXT_START_INDX,
			TOKEN_TEXT_END_INDX - TOKEN_TEXT_START_INDX + 1)))
		return (FAILURE);
	t->val = (void *)token_name;
	return (SUCCESS);
}