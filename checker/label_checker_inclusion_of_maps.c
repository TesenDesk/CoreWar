/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_checker_inclusion_of_maps.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:54:02 by ftothmur          #+#    #+#             */
/*   Updated: 2020/02/28 17:04:34 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "label_checker_private.h"

int					label_checker_inclusion_of_maps(t_vector *label_ptr_keys, t_hash_map *map_of_label_words)
{
	size_t			i;
	void			*curr_label_name;

	i = 0;
	while (i < label_ptr_keys->total)
	{
		curr_label_name = label_ptr_keys->items[i];
		if (ft_hash_map_get(map_of_label_words, curr_label_name) == NULL)
			return (FAILURE);
		++i;
	}	
	return (SUCCESS);
}