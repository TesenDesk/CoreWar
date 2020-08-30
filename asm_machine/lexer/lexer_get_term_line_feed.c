/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_get_term_line_feed.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 12:49:17 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/15 12:49:17 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_lexer.h"

int					lexer_get_term_line_feed(t_lexer *lexer, char const **text,
					int *type, void *token_ptr[2])
{
	(void)lexer;
	(void)token_ptr;
	if (**text != LINE_FEED)
		return (TERM_UNDEFINED_CODE);
	while (**text == LINE_FEED)
		++(*text);
	*type = TOKEN_LFEED;
	return (LINE_FEED_CODE);
}
