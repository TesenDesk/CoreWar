/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_get_term_com_cmd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:29:54 by ftothmur          #+#    #+#             */
/*   Updated: 2020/02/12 21:41:14 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "lexer_private.h"
#include "lexer_utils_private.h"

/*
**	The function determins if this part of text is appropriate term for
** functiom_name token.
**	INPUT:	Pointer to text after COMMENT_CMD_STRING.
**	OUTPUT:	type of term.
*/

int				lexer_get_term_com_cmd(t_lexer *lexer, char const **text, 
				int *type, void *token_ptr[2])
{
	(void)lexer;
	(void)token_ptr;
	lexer_utils_trim_whitespace(text);
	if (lexer_utils_is_quotation_mark(**text))
	{
		++(*text);
		return (COMMENT_CMD_STRING_CODE);
	}
	return (TERM_UNDEFINED_CODE);
}
