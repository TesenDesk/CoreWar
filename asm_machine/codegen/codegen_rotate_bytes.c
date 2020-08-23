/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codegen_rotate_bytes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:10:38 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/23 13:14:24 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_codegen.h"

void		rotate_four_bytes(unsigned int *p)
{
	int			first;
	int			second;
	int			third;
	int			fourth;

	first = (*p & 0x000000ff) << 24;
	second = ((*p & 0xff000000) >> 24);
	third = ((*p & 0x0000ff00) << 8);
	fourth = ((*p & 0x00ff0000) >> 8);
	*p = second | fourth | third | first;
}

void		rotate_two_bytes(unsigned short *p)
{
	*p = *p << 8 | (*p & 0xff00) >> 8;
}

void		rotate_bytes(unsigned int *p, int size)
{
	if (size == 2)
		rotate_two_bytes((unsigned short*)p);
	else if (size == 4)
		rotate_four_bytes(p);
}
