/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_print_dump.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 18:42:20 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/04 18:42:20 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_arena.h"

static void		set_index_in_buffer(char *buffer, int index)
{
	if (index & 0xf000)
		ft_uintmaxtostr(&buffer[2], index, 16, 0);
	else if (index & 0xf00)
		ft_uintmaxtostr(&buffer[3], index, 16, 0);
	else if (index & 0xf0)
		ft_uintmaxtostr(&buffer[4], index, 16, 0);
	else if (index & 0xf)
		ft_uintmaxtostr(&buffer[5], index, 16, 0);
	buffer[6] = ' ';
}

static void		set_octet(char *data, char *buffer, int j, int i)
{
	if (data[j] & 0xf0)
		ft_uintmaxtostr(&buffer[i], ((unsigned int)data[j] & 0xff), 16, 0);
	else
		ft_uintmaxtostr(&buffer[i + 1], (unsigned int)data[j], 16, 0);
}

void			arena_print_dump(t_arena *self)
{
	size_t		j;
	size_t		i;
	char		*buffer;
	char		*data;

	buffer = ft_memalloc(3 * D_LINE_SIZE + PREFIX_SIZE); // dont forget change tp D_LINE_SIZE to DUMP_LINE_SIZE
	data = self->data;
	ft_memcpy(buffer, "0x0000 : ", 9);
	j = 0;
	i = PREFIX_SIZE;
	while (j < MEM_SIZE)
	{
		buffer[i] = '0';
		set_octet(data, buffer, j++, i);
		i += 2;
		if (!(j % D_LINE_SIZE))
		{
			buffer[i] = EOL;
			i = PREFIX_SIZE;
			printf("%s", buffer);
			set_index_in_buffer(buffer, j);
		}
		else
			buffer[i++] = SPACE;
	}
}
