/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_map_get.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 15:33:41 by ftothmur          #+#    #+#             */
/*   Updated: 2020/03/04 16:51:29 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_hash_map_get(t_hash_map *map, void *key)
{
	unsigned long long	index;
	t_keystr_avl_t		*avl_tmp;
	index = ft_hash_map_hashcode((unsigned char *)key) % map->arr_size;
//	printf("%s, %d\n", (char*)key, index);
	if (!map->data[index])
		return (NULL);
	if (!(avl_tmp = ft_keystr_avl_search(map->data[index], key)))
		return (NULL);
	return (avl_tmp->pair->content);
}
