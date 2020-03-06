/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_get_term_name_cmd.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:30:10 by ftothmur          #+#    #+#             */
/*   Updated: 2020/03/06 21:21:51 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "lexer.h"
#include "lexer_private.h"
// #include "lexer_utils_private.h"

/*
**	The function determins if this part of text is appropriate term for
** functiom_name token.
**	INPUT:	Pointer to text after NAME_CMD_STRING.
**	OUTPUT:	type of term.
*/

int				lexer_get_term_name_cmd(t_lexer *lexer, char const **text, 
				int *type, void *token_ptr[2])
{
	(void)lexer;
	(void)token_ptr;

	printf("now:%s\n",  *text);
	lexer_utils_trim_whitespace(text);
	printf("now:%s\n",  *text);
	if (lexer_utils_is_quotation_mark(**text))
	{
		++(*text);
		return (QUOTATION_MARK_CODE);
	}
	return (TERM_UNDEFINED_CODE);
}
