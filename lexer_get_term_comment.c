/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_get_comment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita_toropov <nikita_toropov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 00:24:58 by nikita_toro       #+#    #+#             */
/*   Updated: 2020/02/06 18:04:37 by nikita_toro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "lexer_private.h"


int		lexer_get_term_comment(t_lexer *lexer, char const **text, int *token_type, void *token_ptr[2])
{
	if (!(**text))
	{
        *token_type = TOKEN_UNDEF;
        return (1);
    }
	while (!(**text == '\0' || **text == '\n'))
	    printf("%s\n", *text);
		++(*text);
	return (0);
}
