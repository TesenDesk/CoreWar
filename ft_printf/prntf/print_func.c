/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 20:40:54 by mstygg            #+#    #+#             */
/*   Updated: 2019/09/08 15:36:07 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_and_clear(t_buf_struct *buf_s)
{
	write(1, (U_CHAR*)buf_s->buf, buf_s->size);
	buf_s->counter += buf_s->size;
	buf_s->size = 0;
}

int			ft_checkbit_pf(long long n, int pos)
{
	return ((n & (1UL << pos)) != 0);
}

void		ft_printbits_pf(ULL n, int count)
{
	while (count--)
	{
		ft_putchar_pf(ft_checkbit_pf(n, count) + '0');
		if (!(count % 4 && count))
			ft_putchar_pf(' ');
	}
	ft_putchar_pf('\n');
}

void		print_bytes(t_def_num *ld)
{
	int i;

	i = 15;
	while (i >= 0)
		ft_printbits_pf(ld->point.bytes[i--], 8);
}
