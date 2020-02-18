/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:58:45 by ftothmur          #+#    #+#             */
/*   Updated: 2020/02/10 20:26:53 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "lexer_utils_private.h"

/*
**	The function determins if the symbol is of that class of symbols.
**	INPUT:	ASCII.
**	OUTPUT:	TRUE / FALSE.
*/

int				lexer_utils_is_line_feed(char c)
{
	int			decision;

	decision = (c == LINE_FEED);
	return (decision);
}

/*
**	The function determins if the symbol is of that class of symbols.
**	INPUT:	ASCII.
**	OUTPUT:	TRUE / FALSE.
*/

int				lexer_utils_is_of_label_chars(char c)
{
	int			decision;

	decision = (strchr(LABEL_CHARS, c) != NULL);
	return (decision);
}

/*
**	The function determins if the symbol is of that class of symbols
**	INPUT:	ASCII.
**	OUTPUT:	TRUE / FALSE.
*/

int				lexer_utils_is_label_char(char c)
{
	int			decision;

	decision = (c == LABEL_CHAR);
	return (decision);
}

/*
**	The function determins if the symbol is of that class of symbols
**	INPUT:	ASCII.
**	OUTPUT:	TRUE / FALSE.
*/

int				lexer_utils_is_whitespace(char c)
{
	int			decision;

	decision = (strchr(WHITE_SPACE, c) != NULL);
	return (decision);
}

/*
**	The function determins if the symbol is of that class of symbols
**	INPUT:	ASCII.
**	OUTPUT:	TRUE / FALSE.
*/

int				lexer_utils_is_quotation_mark(char c)
{
	int			decision;

	decision = (c == QUOTATION_MARK);
	return (decision);
}
