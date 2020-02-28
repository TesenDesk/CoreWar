/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_checker_inclusion_of_maps.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:54:02 by ftothmur          #+#    #+#             */
/*   Updated: 2020/02/27 19:52:46 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "label_checker_private.h"

static int			deallocate_deq_return_failure(t_dlist **deq)
{
	ft_dlstdel(deq, ft_delfunc_dummy);
	return (FAILURE);
}

static int			put_descendants_to_que(t_dlist **deq,
					t_keystr_avl_t *element)
{
	t_dlist			*new;
	
	new = NULL;
	if (element->left)
	{
		if (!(new = ft_dlstnew_ptr(element->left)))
			return (deallocate_deq_return_failure(&deq));
		ft_dlstadd(&deq, new);
	}
	if (element->right)
	{
		if (!(new = ft_dlstnew_ptr(element->left)))
			return (deallocate_deq_return_failure(&deq));
		ft_dlstadd(&deq, new);
	}
	return (SUCCESS);
}

static int			tree_traversal(t_keystr_avl_t	*tree_element)
{
	t_dlist			*deq;
	
	deq = NULL;
	if (put_descendants_to_que(&deq, tree_element) == FAILURE)
		return (FAILURE);
	new = ft_dlstpop(deq);
	while (new)
	{
		if (put_descendants_to_que(&deq, tree_element) == FAILURE)
			return (FAILURE);
	}
	ft_dlstdel(deq, ft_delfunc_dummy);
	return (SUCCESS);
}

int					label_checker_inclusion_of_maps(t_hash_map
					*map_of_label_ptrs, t_hash_map *map_of_label_words)
{
	size_t			i;
	t_keystr_avl_t	*tree_element;

	i = 0;
	while (i < map_of_label_ptrs->arr_size)
	{
		if ((tree_element = map_of_label_ptrs->data[i]) != NULL)
			if (tree_traversal(tree_element) == FAILURE)
				return (FAILURE);
		
		++i;
	}
	return (SUCCESS);
}