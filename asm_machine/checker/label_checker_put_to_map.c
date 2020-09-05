/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_checker_put_to_map.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:33:48 by ftothmur          #+#    #+#             */
/*   Updated: 2020/07/19 20:38:52 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "label_checker_private.h"
#include "codegen.h"

/*
**	The function adds a unique "label word" name to the assiciative array.
**	INPUT:	ptr to the associative array, ptr to text where "label word" name
** begings.
**	OUTPUT:	did the operation succeed.
*/

int					label_checker_put_to_map_label_word(
					t_hash_map **map_of_label_words, t_token *token)
{
	t_pair			pair;

	pair.key = token_get_value(token);
	pair.content = token_get_token_ptr(token, 0);
	if (ft_hash_map_get(*map_of_label_words, pair.key))
		return (FAIL);
	if (ft_hash_map_set(map_of_label_words, pair.key, pair.content) == FAIL)
		return (FAIL);
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
					t_vector *added_label_ptrs, t_token *token)
{
	t_label_data	*data;

	if (!(data = (t_label_data*)ft_memalloc(sizeof(t_label_data))))
		exit(-1);
	data->name = token_get_value(token);
	data->add = token_get_token_ptr(token, 0);
	if (ft_vector_add(added_label_ptrs, data) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
