/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_map_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 15:31:44 by ftothmur          #+#    #+#             */
/*   Updated: 2020/03/04 16:45:03 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_hash_map_set(t_hash_map **map, void *key, void *content)
{
	t_pair *pair;

	if (!(pair = malloc(sizeof(t_pair))))
		return (FAIL);
	pair->key = key;
	pair->content = content;
	return (ft_hash_map_put_to_map(map, pair));
}
