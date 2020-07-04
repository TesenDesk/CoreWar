/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_write_four_bytes_to_data.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 19:18:37 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/04 19:18:37 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_arena.h"

void		arena_write_four_bytes_to_data(t_arena *self, int pos, int new_data)
{
	char	*data;
	int		i;
	char	new_char_value;

	data = self->data;
	if (pos < 0)
		pos = MEM_SIZE + pos % MEM_SIZE;
	i = 0;
	while (i < 4)
	{
		new_char_value = (char)(new_data >> ((3 - i) * EIGHT_BITS));
		data[(pos + i) % MEM_SIZE] = new_char_value;
		i++;
	}
}
