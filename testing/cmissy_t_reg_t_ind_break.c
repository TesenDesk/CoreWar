/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmissy_t_reg_t_ind_break.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:05:13 by cmissy            #+#    #+#             */
/*   Updated: 2020/02/07 18:34:23 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

#define UNDEFINED_TOKEN			-1;
#define SEPARATOR_CHAR			','

typedef struct 	s_token
{
	int			token_type;
}				t_token;


void		tkn_get_arg_t_reg(t_token *token, const char **text)
{
	int		num_of_reg;

	*text += 1;
	if (!ft_isdigit(**text) ||
	(num_of_reg = ft_atoi(*text)) > 16 || num_of_reg < 1)
	{
		token->token_type = UNDEFINED_TOKEN;
		return ;
	}
	while (ft_isdigit(*text))
		++(*text);
	if (**text != SEPARATOR_CHAR)
		token->token_type = UNDEFINED_TOKEN;
	return ;
}

void		tkn_get_arg_t_ind(t_token *token, const char **text)
{
	*text += 1;
	if 
}
// void		tkn_get_break(t_token *token, const char **text)
// {
// }


// void		tkn_get_comment(t_token *token, const char **text)
// {
// 	*text += 1;
// 	if (**text == '\n' || **text == '\0')
// 		token->token_type = UNDEFINED_TOKEN;
// 	while (!**text && **text != '\n')
// 		++(*text);
// 	return ;
// }

int		main(void)
{
	int		cntr;
	char	*line;
	char	*tmp;
	t_token	token;

	token.token_type = 0;
	while (get_next_line(0, &line))
	{
		// printf("%s\n", line);
		tmp = line;
		while (*tmp)
		{
			if (*tmp == '#' || *tmp == ';')
			{
				// printf("%s\n", tmp);
				tkn_get_comment(&token, (const char**)&tmp);
				if (token.token_type == -1)
					printf("token_type changed to UNDEFINED_TOKEN\n\n");
				else
					printf("comment defined\n\n");
				token.token_type = 0;
			}
			else
				tmp++;
		}
		free(line);
	}
}
