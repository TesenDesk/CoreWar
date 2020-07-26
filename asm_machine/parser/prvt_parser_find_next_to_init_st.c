/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_parser_find_next_to_init_st.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 19:36:16 by ftothmur          #+#    #+#             */
/*   Updated: 2020/07/26 19:41:43 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

int	prvt_parser_find_next_to_init_st(int token_type)
{
	if (token_type == TOKEN_CHNAME || token_type == TOKEN_CHCOM)
		return (PARSER_LINE_END_ST);
	else if (token_type >= TOKEN_AFF && token_type <= TOKEN_LFORK)
		return (prvt_find_parser_op0_state(token_type));
	else if (token_type == TOKEN_LFEED || token_type == TOKEN_EOF)
		return (PARSER_INIT_ST);
	else if (token_type == TOKEN_LABEL_WORD)
		return (PARSER_FINISH_ST);
	else
		return (PARSER_ERROR);
}
