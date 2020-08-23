/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 21:30:23 by ftothmur          #+#    #+#             */
/*   Updated: 2020/03/01 16:49:30 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_vector_add(t_vector *v, void *item)
{
	if (!v ||
			(v->capacity == v->total &&
			ft_vector_resize(v, (ssize_t)v->capacity * 2) == FAIL))
		return (FAIL);
	v->items[v->total++] = item;
	return (SUCCESS);
}
