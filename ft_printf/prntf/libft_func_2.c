/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_func_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 18:32:14 by mstygg            #+#    #+#             */
/*   Updated: 2019/09/02 14:15:22 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_pf(char c)
{
	write(1, &c, 1);
}

ULL		ft_pow(ULL base, int exp)
{
	ULL res;
	ULL pow;

	res = 1;
	pow = base;
	while (exp)
	{
		if ((exp & 1))
			res *= pow;
		pow *= pow;
		exp >>= 1;
	}
	return (res);
}

void	ft_bzero_pf(void *s, size_t n)
{
	if (n <= 0)
		return ;
	while (n--)
		*(unsigned char*)s++ = 0;
}
