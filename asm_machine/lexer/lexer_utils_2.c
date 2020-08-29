/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:47:03 by ftothmur          #+#    #+#             */
/*   Updated: 2020/07/19 19:30:47 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_lexer_utils.h"

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

long long		lexer_utils_trim_not_eof_not_line_feed_not_quotatuion_mark(
				const char **text)
{
    long long   counter;

    counter = 0;
	while (
		!lexer_utils_is_eof(**text) &&
//		!lexer_utils_is_line_feed(**text) &&
		!lexer_utils_is_quotation_mark(**text))
	{
		++(*text);
		counter += 1;
	}
//	printf("counter:%d\n", counter);
	return (counter);
}
