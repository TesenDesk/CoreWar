/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_get_n_bytes_from.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 19:10:36 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/04 19:10:37 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_arena.h"

int			arena_get_n_bytes_from(t_arena *self, int pos, int num_of_bytes)
{
	char	*data;
	int		four_bytes;
	int		i;

	if (num_of_bytes < 1 || num_of_bytes > 4 || num_of_bytes == 3)
	{
		printf("Wrong num_of_bytes in ARENA_GET_N_BYTES_FROM fix it\n");
		raise(__FILE__, __LINE__, ENOMEMORY); // dont forget change ERRMSGINDEX
	}
	if (pos < 0)
		pos = MEM_SIZE + pos % MEM_SIZE;
	data = (char*)(self->data);
	four_bytes = data[pos % MEM_SIZE];
	i = 1;
	while (i < num_of_bytes)
	{
		four_bytes = four_bytes << EIGHT_BITS;
		four_bytes |= (int)data[(pos + i) % MEM_SIZE] & 0xff;
		i++;
	}
	return (four_bytes);
}
