/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_name_ch_comment_func.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:51:57 by ftothmur          #+#    #+#             */
/*   Updated: 2020/02/05 17:32:12 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "token.h"

#define SUCCESS		0
#define FAILURE		(-1)

typedef struct 	    s_token
{
    int             token_type;
    void		    *tkn_begin;
    size_t		    tkn_len;
}				    t_token;

typedef struct 	    s_lexer
{
    int             state;
    t_token         (*fptr_form_token)(struct s_lexer *lexer, char **str);
}				    t_lexer;

static int		is_white_space(char c)
{
	int			result;

	result = (c == '\t' || c == ' ');
	return (result);
}

static int		markout_token(t_token *token, const char *str)
{
	char			*end;

	while (is_white_space(*str))
		++str;
	if (*str == QUOTATION_MARK)
		++str;
	else
	{
		token->token_type = UNDEFINED_TOKEN;
		return (FAILURE);
	}
	if (!(end = ft_strchr(str, QUOTATION_MARK)))
	{
		token->token_type = UNDEFINED_TOKEN;
		return (FAILURE);
	}	
	token->tkn_begin = str;
	token->tkn_len = end - str;
	return (SUCCESS);
}

void			lexer_ch_name(t_token *token, const char *str)
{
	str += ft_strlen(NAME_CMD_STRING) - 1;
	if (markout_token(token, *str) == FAILURE)
		return ;
	token->token_type = CH_NAME;
	return ;
}

void			lexer_ch_comment(t_token *token, const char *str)
{
	str += ft_strlen(COMMENT_CMD_STRING) - 1;
	if (markout_token(token, *str) == FAILURE)
		return ;
	token->token_type = CH_COMMENT;
	return ;
}