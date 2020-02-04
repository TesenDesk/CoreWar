/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_name_ch_comment_func.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:51:57 by ftothmur          #+#    #+#             */
/*   Updated: 2020/02/04 18:29:55 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

typedef struct 	s_lexer
{
	char		*str;
	int			token;
}				t_lexer;

static int		is_white_space(char c)
{
	int			result;

	result = (c == '\t' || c == ' ');
	return (result);
}

void			lexer_ch_name(t_lexer *lexer, const char *str)
{
	char			*end;

	str += ft_strlen(NAME_CMD_STRING);
	while (is_white_space(*str))
		++str;
	if (*str == QUOTATION_MARK)
		++str;
	else
	{
		lexer->token = UNDEFINED_TOKEN;
		return ;
	}
	if (!(end = ft_strchr(str, QUOTATION_MARK)))
	{
		lexer->token = UNDEFINED_TOKEN;
		return ;
	}	
	lexer->str = str;
	lexer->len = end - str;;
	lexer->token = CH_NAME;
	return ;
}

void			lexer_ch_comment(t_lexer *lexer, const char *str)
{
	char			*end;

	str += ft_strlen(NAME_CMD_STRING);
	while (is_white_space(*str))
		++str;
	if (*str == QUOTATION_MARK)
		++str;
	else
	{
		lexer->token = UNDEFINED_TOKEN;
		return ;
	}
	if (!(end = ft_strchr(str, QUOTATION_MARK)))
	{
		lexer->token = UNDEFINED_TOKEN;
		return ;
	}
	lexer->str = str;
	lexer->len = end - str;
	lexer->token = CH_COMMENT;
	return ;
}