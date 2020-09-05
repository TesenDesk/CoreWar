/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_terms_is_op.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 20:30:04 by jjerde            #+#    #+#             */
/*   Updated: 2020/08/30 20:38:32 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_lexer.h"

int		term_is_op(char const *text)
{
	static char		*cmds_arr[16] = {
		LFORK_NAME, FORK_NAME, LIVE_NAME, LLDI_NAME, ZJMP_NAME, ADD_NAME,
		AFF_NAME, AND_NAME, LDI_NAME, LLD_NAME, STI_NAME, SUB_NAME, XOR_NAME,
		LD_NAME, OR_NAME, ST_NAME,
	};
	int				i;
	int				len;

	i = 0;
	while (i < 16)
	{
		len = ft_strlen(cmds_arr[i]);
		if (ft_strnstr2(text, cmds_arr[i], len))
			if (text[len] == ' ' || text[len] == '\t')
				return (len);
		i++;
	}
	return (0);
}

int		find_op2_type(char const *text)
{
	if (ft_strnstr2(text, LD_NAME, ft_strlen(LD_NAME)))
		return (TOKEN_LD);
	else if (ft_strnstr2(text, OR_NAME, ft_strlen(OR_NAME)))
		return (TOKEN_OR);
	else if (ft_strnstr2(text, ST_NAME, ft_strlen(ST_NAME)))
		return (TOKEN_ST);
	return (0);
}

int		find_op3_type(char const *text)
{
	if (ft_strnstr2(text, ADD_NAME, ft_strlen(ADD_NAME)))
		return (TOKEN_ADD);
	else if (ft_strnstr2(text, AFF_NAME, ft_strlen(AFF_NAME)))
		return (TOKEN_AFF);
	else if (ft_strnstr2(text, AND_NAME, ft_strlen(AND_NAME)))
		return (TOKEN_AND);
	else if (ft_strnstr2(text, LDI_NAME, ft_strlen(LDI_NAME)))
		return (TOKEN_LDI);
	else if (ft_strnstr2(text, LLD_NAME, ft_strlen(LLD_NAME)))
		return (TOKEN_LLD);
	else if (ft_strnstr2(text, STI_NAME, ft_strlen(STI_NAME)))
		return (TOKEN_STI);
	else if (ft_strnstr2(text, SUB_NAME, ft_strlen(SUB_NAME)))
		return (TOKEN_SUB);
	else if (ft_strnstr2(text, XOR_NAME, ft_strlen(XOR_NAME)))
		return (TOKEN_XOR);
	return (0);
}

int		find_op4_type(char const *text)
{
	if (ft_strnstr2(text, FORK_NAME, ft_strlen(FORK_NAME)))
		return (TOKEN_FORK);
	else if (ft_strnstr2(text, LIVE_NAME, ft_strlen(LIVE_NAME)))
		return (TOKEN_LIVE);
	else if (ft_strnstr2(text, LLDI_NAME, ft_strlen(LLDI_NAME)))
		return (TOKEN_LLDI);
	else if (ft_strnstr2(text, ZJMP_NAME, ft_strlen(ZJMP_NAME)))
		return (TOKEN_ZJMP);
	return (0);
}

int		find_op5_type(char const *text)
{
	if (ft_strnstr2(text, LFORK_NAME, ft_strlen(LFORK_NAME)))
		return (TOKEN_LFORK);
	return (0);
}
