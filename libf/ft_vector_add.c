/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 21:30:23 by ftothmur          #+#    #+#             */
/*   Updated: 2020/02/28 19:11:43 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_vector_add(t_vector *v, void *item)
{
	if (!v ||
			(v->capacity == v->total &&
			ft_vector_resize(v, (ssize_t)v->capacity * 2) == FAILURE))
		return (FAILURE);
	write(1, "there", 5);
	v->items[v->total++] = item;
	write(1, "there", 5);
	return (SUCCESS);
}
