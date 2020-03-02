/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_traversal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:58:59 by ftothmur          #+#    #+#             */
/*   Updated: 2020/02/28 15:05:47 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_vector_traversal(t_vector *v, int (*fptr)(void *specific_item))
{
	int		index;

	index = 0;
	while (index < v->total)
	{
		if (fptr(v->items[index]) == FAILURE)
			return (FAILURE);
		++index;
	}
	return (SUCCESS);
}
