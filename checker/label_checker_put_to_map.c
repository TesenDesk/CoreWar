/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_checker_put_to_map.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:33:48 by ftothmur          #+#    #+#             */
/*   Updated: 2020/03/04 19:51:44 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "label_checker_private.h"

/*
**	The function adds a unique "label word" name to the assiciative array.
**	INPUT:	ptr to the associative array, ptr to text where "label word" name
** begings. 
**	OUTPUT:	did the operation succeed.
*/

int					label_checker_put_to_map_label_word(
					t_hash_map **map_of_label_words, t_expr *expr)
{
	t_pair			pair;

	pair.key = token_get_value((t_token *)(expr->args[OP_NAME].value));
	pair.content = TRUE;
	if (ft_hash_map_get(*map_of_label_words, pair.key))
		return (FAILURE);
	if (ft_hash_map_set(map_of_label_words, pair.key, pair.content) == FAILURE)
		return (FAILURE);
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
					t_vector *added_label_ptrs, t_expr *expr)
{
	t_pair			pair;
	
	pair.key = token_get_value((t_token *)(expr->args[OP_NAME].value));
	pair.content = TRUE;
	if (ft_vector_add(added_label_ptrs, (void *)pair.key) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
