/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_find_parser_op0_state.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 19:04:05 by ftothmur          #+#    #+#             */
/*   Updated: 2020/07/26 19:41:38 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

int	prvt_find_parser_op0_state(int token_type)
{
	if (token_type >= TOKEN_LIVE && token_type <= TOKEN_LFORK)
		return (PARSER_OP0_LIFE_ST);
	else if (token_type == TOKEN_AFF)
		return (PARSER_OP0_AFFECT_ST);
	else if (token_type >= TOKEN_LD && token_type <= TOKEN_LLD)
		return (PARSER_OP0_LOAD_ST);
	else if (token_type == TOKEN_ST)
		return (PARSER_OP0_STORE_ST);
	else if (token_type >= TOKEN_ADD && token_type <= TOKEN_SUB)
		return (PARSER_OP0_ARITHM_ST);
	else if (token_type >= TOKEN_LDI && token_type <= TOKEN_LLDI)
		return (PARSER_OP0_LOADI_ST);
	else if (token_type >= TOKEN_AND && token_type <= TOKEN_XOR)
		return (PARSER_OP0_LOGIC_ST);
	else if (token_type == TOKEN_STI)
		return (PARSER_OP0_STORI_ST);
	return (0);
}
