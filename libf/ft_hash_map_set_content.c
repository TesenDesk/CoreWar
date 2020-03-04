/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_map_set_content.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:34:40 by ftothmur          #+#    #+#             */
/*   Updated: 2020/03/04 16:58:16 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_hash_map_set_content(t_hash_map *map, void *key,
							void *new_content)
{
	unsigned long long	index;
	t_keystr_avl_t		*avl_tmp;

	index = ft_hash_map_hashcode((unsigned char *)key) % map->arr_size;
	if (!(avl_tmp = ft_keystr_avl_search(map->data[index], key)))
		return (FAILURE);
	avl_tmp->pair->content = new_content;
	return (SUCCESS);
}
