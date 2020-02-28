/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_checker_put_to_map.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:33:48 by ftothmur          #+#    #+#             */
/*   Updated: 2020/02/28 18:25:40 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "label_checker_private.h"

static int			deallocate_pair_key_return_failure(t_pair *pair)
{
	free(pair->key);
	return (FAILURE);
}

/*
**	The function adds a unique "label word" name to the assiciative array.
**	INPUT:	ptr to the associative array, ptr to text where "label word" name
** begings. 
**	OUTPUT:	did the operation succeed.
*/

int					label_checker_put_to_map_label_word(
					t_hash_map **map_of_label_words, char const **text,
					size_t label_len)
{
	t_pair			pair;

	// if (!(pair.key = ft_strsub(*text, *text, label_len - 1)))
	if (!(pair.key = ft_strsub(*text, 0, label_len - 1)))
		return (FAILURE);
	pair.content = pair.key;
	if (ft_hash_map_get(*map_of_label_words, pair.key))
		return (deallocate_pair_key_return_failure(&pair));
	if (ft_hash_map_set(map_of_label_words, pair.key, pair.content) == FAILURE)
		return (deallocate_pair_key_return_failure(&pair));
	// free(pair.key);
	return (SUCCESS);
}

/*
**	The function adds "label ptr" to the assiciative array if name of the
** "label ptr" have not been seen before, otherwize do notnthing.
**	INPUT:	ptr to the associative array, ptr to text where "label word" name
** begings. 
**	OUTPUT:	did the operation succeed.
*/

int					label_checker_put_to_map_label_ptr(
					t_hash_map **map_of_label_ptrs, t_vector *added_label_ptrs,
					char const **text, size_t label_len)
{
	t_pair			pair;
	
	// if (!(pair.key = ft_strsub(*text, *text, label_len - 1)))
	if (!(pair.key = ft_strsub(*text, 0, label_len - 1)))
		return (FAILURE);
	pair.content = pair.key;
	if (ft_hash_map_get(*map_of_label_ptrs, pair.key) == NULL)
	{
		if (ft_hash_map_set(map_of_label_ptrs, pair.key, pair.content)
			== FAILURE)
			return (deallocate_pair_key_return_failure(&pair));
		if (ft_vector_add(added_label_ptrs, (void *)pair.key) == FAILURE)
			return (deallocate_pair_key_return_failure(&pair));
	}
	else
	{
		ft_memdel((void **)&pair.key);
		pair.content = NULL;
	}
	// free(pair.key);
	return (SUCCESS);
}
