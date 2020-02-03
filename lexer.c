/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:39:31 by ftothmur          #+#    #+#             */
/*   Updated: 2020/02/03 18:51:34 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct 	s_lexer
{
	char		*str;
	int			token;
}				t_lexer;

void			lexer_ctor(t_lexer *lexer)
{
	return ;
}

void			lexer_dtor(t_lexer *lexer)
{
	return ;
}

int				get_token_id()
{
	return ();
}

char			*get_token_str()
{
	return ();
}