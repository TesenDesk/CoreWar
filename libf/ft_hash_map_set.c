/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_map_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 15:31:44 by ftothmur          #+#    #+#             */
/*   Updated: 2020/03/01 17:03:21 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			push_to_map(t_hash_map **map_input, t_pair *pair)
{
	ULL				index;
	t_hash_map		*map;

	map = *map_input;
	index = ft_hash_map_hashcode((U_CHAR*)pair->key) % map->arr_size;
	if (!(map->data[index] = ft_keystr_avl_insert(map->data[index], pair)))
		return (FAILURE);
	++map->map_size;
	return (SUCCESS);
}

int					ft_hash_map_set(t_hash_map **map, void *key, void *content)
{
	t_pair *pair;

	if (!(pair = malloc(sizeof(t_pair))))
		return (0);
	pair->key = key;
	pair->content = content;
	return (push_to_map(map, pair));
}
