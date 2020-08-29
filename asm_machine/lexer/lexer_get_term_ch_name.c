/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_get_term_ch_name.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:13:53 by ftothmur          #+#    #+#             */
/*   Updated: 2020/07/15 12:47:09 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_lexer.h"

/*
**	The function determins if this part of text is appropriate term for
** functiom_name token.
**	INPUT:	Pointer to text after NAME_CMD_STRING.
**	OUTPUT:	type of term.
*/

int				lexer_get_term_ch_name(t_lexer *lexer, char const **text,
				int *type, void *token_ptr[2])
{
    long long   counter;
	(void)lexer;
	token_ptr[TOKEN_START_PTR] = (void*)*text;
	counter = lexer_utils_trim_not_eof_not_line_feed_not_quotatuion_mark(text);
    if (counter > 128)
    {
       ft_printf("Champion name too long (Max length 128)\n");
       exit(-1);
    }

	if (lexer_utils_is_quotation_mark(**text))
	{
		*type = TOKEN_CHNAME;
		token_ptr[TOKEN_END_PTR] = (void*)(*text - 1);
//		ft_printf("1:%.5s\n", token_ptr[TOKEN_START_PTR]);
//		ft_printf("2:%.5s\n", token_ptr[TOKEN_END_PTR]);
		++(*text);
		return (QUOTATION_MARK_CODE);
	}
	return (TERM_UNDEFINED_CODE);
}
