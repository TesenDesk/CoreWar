/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_free_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:52:35 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/19 14:22:25 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_vector_free_data(t_vector *v, void (*fptr)(void **))
{
	int 		tmp;

	tmp = v->capacity;
	if (!v || !fptr)
		return ;
	if (fptr)
		while (tmp)
		{
//			printf("%d\n", tmp);
			(*fptr)((void **) (v->items[tmp]));
			v->items[tmp] = NULL;
			--tmp;
		}
	free(v->items);
		v->items = NULL;
	return ;
}
