/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strint_ou_flow.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:12:39 by ftothmur          #+#    #+#             */
/*   Updated: 2020/02/18 22:11:24 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*travers_nbr_str(char *str)
{
	while (ft_isdigit(*str))
		++str;
	return (str);
}

int					ft_strint_ou_flow(char *str, int *nbr)
{
	char			*top;
	char			*tip;

	if (!str || !nbr)
		return (FAIL);
	if ((*nbr = ft_atoi(str)) == INT_MAX || *nbr == INT_MIN)
	{
		top = str;
		if (*top == '+' || *top == '-')
			++top;
		tip = travers_nbr_str(top);
		if ((ft_strncmp("214748364", top, tip - top)) ||
				(*(top + 9) != '7' && (*nbr > 0)) ||
				(*(top + 9) != '8' && (*nbr < 0)))
			return (FAIL);
	}
	return (SUCCESS);
}
