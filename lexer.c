/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:39:31 by ftothmur          #+#    #+#             */
/*   Updated: 2020/02/04 18:29:53 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_private.h.h"

void                lexer_constructor(t_lexer **lexer)
{
	if (!(*lexer = (t_lexer*)malloc(sizeof(t_lexer))))
	{
		printf("error\n");
		exit(-1);
	}
	(*lexer)->state = 0;
	(*lexer)->form_token = form_token;
}

void                lexer_destructor(t_lexer **lexer)
{
	free(*lexer);
	*lexer = NULL;
}


void                token_constructor(t_token **token)
{
	if (!(*token = (t_token*)malloc(sizeof(t_token))))
	{
		printf("error\n");
		exit(-1);
	}
	(*token)->tkn_type = 0;
	(*token)->tkn_begin = NULL;
	(*token)->tkn_end = NULL;
	(*token)->tkn_len = 0;
}
//
//int				lexer_get_token_id(t_lexer *lexer)
//{
//	return ();
//}
//
//char			*lexer_get_token_str(t_lexer *lexer)
//{
//	return ();
//}