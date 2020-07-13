/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_print_dump.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 18:42:20 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/13 17:03:44 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_arena.h"

void			arena_print_dump(t_arena *self)
{
	int			i;
	char		*data;

	data = self->data;
	i = 0;
	printf("0x%.4x : ", i);
	while (i < MEM_SIZE)
	{
		printf("%.2x ", data[i++] & 0xff);
		if (i % DUMP_LINE_SIZE == 0 && i < MEM_SIZE)
			printf("\n0x%04x : ", i);
	}
	printf("\n");
}
