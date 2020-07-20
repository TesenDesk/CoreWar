/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 18:58:53 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/15 18:58:53 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		ft_atol(const char *str)
{
	long long	res;
	int			sign;

	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	sign = *str == '-' ? -1 : 1;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		if (res * 10 / 10 != res || res * 10 + (*(str) - '0') < 0)
			return (sign > 0 ? -1 : 0);
		res = res * 10 + (*(str++) - '0');
	}
	return (res * sign);
}
