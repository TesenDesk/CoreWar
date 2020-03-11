/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_map_put_to_map.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:43:19 by ftothmur          #+#    #+#             */
/*   Updated: 2020/03/04 17:01:30 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_hash_map_put_to_map(t_hash_map **map_input,
							t_pair *pair)
{
	unsigned long long	index;
	t_hash_map			*map;

	map = *map_input;
	index = ft_hash_map_hashcode((U_CHAR*)pair->key) % map->arr_size;
	if (!(map->data[index] = ft_keystr_avl_insert(map->data[index], pair)))
		return (FAILURE);
	++map->map_size;
	return (SUCCESS);
}
