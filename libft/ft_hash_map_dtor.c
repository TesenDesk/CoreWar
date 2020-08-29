/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_map_dtor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 15:26:51 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/29 19:01:03 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_hash_map_dtor(t_hash_map **map_input)
{
	t_hash_map		*map;
	size_t			i;

	map = *map_input;
	i = 0;
	while (i < map->arr_size)
	{
		ft_keystr_avl_del(&(map->data[i++]));
	}
	free(map->data);
	map->data = NULL;
	free(map);
	*map_input = NULL;
	return ;
}

void				ft_hash_map_dtor_full(t_hash_map **map_input, t_delfptr f)
{
	t_hash_map		*map;
	size_t			i;

	map = *map_input;
	i = 0;
	while (i < map->arr_size)
	{
		ft_keystr_avl_del_full(&(map->data[i++]), f);
	}
	free(map->data);
	map->data = NULL;
	free(map);
	*map_input = NULL;
	return ;
}
