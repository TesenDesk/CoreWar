/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_get_comment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 00:24:58 by nikita_toro       #+#    #+#             */
/*   Updated: 2020/02/07 11:44:29 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#define UNDEFINED_TOKEN   -1;

typedef struct 	s_token
{
	int			token_type;
}				t_token;

void		tkn_get_comment(t_token *token, const char **text)
{
	*text += 1;
	if (**text == '\n' || **text == '\0')
		token->token_type = UNDEFINED_TOKEN;
	while (!**text && **text != '\n')
		++(*text);
	return ;
}

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
