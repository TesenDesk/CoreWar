/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_parser_find_next_to_op2_st.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 19:43:57 by ftothmur          #+#    #+#             */
/*   Updated: 2020/07/26 19:44:35 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

int	prvt_parser_find_next_to_op2_st(t_parser *parser, int token_type)
{
	if (token_type == TOKEN_TREG)
		return (PARSER_LINE_END_ST);
	else if (token_type == TOKEN_TDIR_INT || token_type == TOKEN_TDIR_LAB)
		if (parser->state == PARSER_OP2_STORI_ST)
			return (PARSER_LINE_END_ST);
	return (PARSER_ERROR);
}
