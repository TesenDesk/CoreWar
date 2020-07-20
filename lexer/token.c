/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 21:54:22 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/19 20:15:05 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_token.h"

t_token				*token_constructor(int type, void *ptr[2])
{
	t_token			*token;
	int				size;

	if (ptr[1] < ptr[0] && type == TOKEN_LABEL_WORD)
	{
		printf("smth_wrong");
		exit(-1);
	}
	if (!(token = (t_token*)malloc(sizeof(t_token))))
		exit(-1);
	if (ptr[1] - ptr[0] < 0)
		token->val = "";
	else
	{
		size = ptr[1] - ptr[0] + 2;
		if (!(token->val = ft_memalloc(size)))
			exit(-1);
		ft_memcpy(token->val, ptr[0], size - 1);
	}
	token->type = type;
	token->token_ptr[0] = ptr[0];
	token->token_ptr[1] = ptr[1];
	token->get_type = token_get_type;
	return (token);
}
