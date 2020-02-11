/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:47:03 by ftothmur          #+#    #+#             */
/*   Updated: 2020/02/10 20:45:57 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "lexer_utils_private.h"

/*
**	The function changes variable which is pointer to text. It moves the 
** pointer after all the white_spaces.
**	INPUT:	ASCII.
**	OUTPUT:	TRUE / FALSE.
*/

void			lexer_utils_trim_whitespace(const char **text)
{
	while (lexer_utils_is_whitespace(**text))
		++(*text);
	return ;
}

/*
**	The function determins if the symbol is of that class of symbols.
**	INPUT:	ASCII.
**	OUTPUT:	TRUE / FALSE.
*/

int				lexer_utils_is_eof(char c)
{
	int			decision;

	decision = !c;
	return (decision);
}

void			lexer_utils_trim_not_eof_not_line_feed_not_quotatuion_mark(
				const char **text)
{
	while (
		!lexer_utils_is_eof(**text) &&
		!lexer_utils_is_line_feed(**text) &&
		!lexer_utils_is_quotation_mark(**text))
	{
		++(*text);
	}
	return ;
}