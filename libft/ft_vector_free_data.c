/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_free_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:52:35 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/29 19:01:03 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_vector_free_data(t_vector *v, void (*fptr)(void **))
{
	int			tmp;

	tmp = 0;
	if (!v || !fptr)
		return ;
	if (fptr)
		while (tmp < v->total)
		{
			(*fptr)((void **)(&(v->items[tmp])));
			v->items[tmp] = NULL;
			++tmp;
		}
	free(v->items);
	v->items = NULL;
	return ;
}
