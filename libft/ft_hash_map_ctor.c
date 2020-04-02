/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashmap_ctor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 15:22:41 by ftothmur          #+#    #+#             */
/*   Updated: 2020/02/28 15:44:33 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_hash_map			*ft_hash_map_ctor(size_t arr_size)
{
	t_hash_map		*new_map;

	if (!(new_map = (t_hash_map *)malloc(sizeof(t_hash_map))))
		return (NULL);
	if (!(new_map->data = ft_memalloc(arr_size * sizeof(t_keystr_avl_t*))))
		return (NULL);
	new_map->arr_size = arr_size;
	new_map->map_size = 0;
	return (new_map);
}
