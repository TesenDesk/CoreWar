/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codegen_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:43:04 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/23 13:44:04 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_codegen.h"

int				ft_checkbit(char n, int pos)
{
	return ((n & (1 << pos)) != 0);
}

void			ft_printbits(char n, int count)
{
	while (count--)
	{
		ft_printf("%c", ft_checkbit(n, count) + '0');
		if (!(count % 4 && count))
			ft_putchar(' ');
	}
	ft_putchar('\n');
}
