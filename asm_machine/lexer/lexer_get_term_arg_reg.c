/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_get_term_arg_reg.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 12:46:13 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/15 12:46:14 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_lexer.h"

int				lexer_get_term_arg_reg(t_lexer *lexer, char const **text,
					int *type, void *token_ptr[2])
{
	int			num;

	*type = TOKEN_TREG;
	(void)lexer;
	if (!ft_isdigit(**text) || (num = ft_atol(*text)) < REG_MIN_NUMBER ||
			num > REG_NUMBER)
	{
		*type = TOKEN_UNDEF;
		return (TERM_UNDEFINED_CODE);
	}
	token_ptr[TOKEN_START_PTR] = (void*)(*text);
	while (ft_isdigit(**text))
		++(*text);
	token_ptr[TOKEN_END_PTR] = (void*)(*text - 1);
	return (INTEGER_CODE);
}
