/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 21:41:10 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/23 15:25:37 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_vector_free(t_vector *v)
{
	ft_memdel((void **)&v->items);
	return ;
}


void				ft_vector_free_full(t_vector *v, t_delfptr f)
{
	f((void**)(&(v->items)));
	return ;
}
