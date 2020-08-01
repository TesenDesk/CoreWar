/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_func_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:18:24 by mstygg            #+#    #+#             */
/*   Updated: 2019/03/28 16:03:58 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long		ft_atol_pf(const U_CHAR *str)
{
	long long	num;
	char		sign;
	long long	check;

	num = 0;
	sign = 1;
	while ((*str <= 13 && *str >= 9) || *str == 32)
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		++str;
	}
	while (*str >= '0' && *str <= '9')
	{
		check = num;
		num *= 10;
		if (num / 10 != check)
			return (sign < 0) ? (0) : (-1);
		num += (*str++ - '0');
		if (num < 0)
			return (sign < 0) ? (0) : (-1);
	}
	return (num * sign);
}

void			*ft_memcpy_pf(void *dst, const void *src, size_t n)
{
	void	*tmp;

	if (!dst && !src)
		return (NULL);
	tmp = dst;
	while (n--)
		*(U_CHAR*)dst++ = *(U_CHAR*)src++;
	return (tmp);
}

size_t			ft_strlen_pf(const U_CHAR *s)
{
	const U_CHAR	*tmp;

	tmp = s;
	while (*tmp++)
		;
	return (tmp - s - 1);
}

U_CHAR			*ft_strchr_pf(const U_CHAR *s, int c)
{
	U_CHAR ch;

	ch = c;
	if (ch == 0)
		return ((U_CHAR*)(s + ft_strlen_pf(s)));
	if (!s)
		return (NULL);
	while (*s && *s != ch)
		++s;
	return (*s) ? ((U_CHAR*)s) : (NULL);
}

U_CHAR			*ft_strndup(const U_CHAR *src, size_t len)
{
	U_CHAR	*dest;
	U_CHAR	*tmp;

	if (!(dest = (U_CHAR*)malloc((ft_strlen_pf(src) + 1) * sizeof(U_CHAR))))
		return (NULL);
	tmp = dest;
	while (len-- && (*dest++ = *src++))
		;
	return (tmp);
}
