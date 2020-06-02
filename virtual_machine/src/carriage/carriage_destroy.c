/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 22:59:21 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/10 13:17:29 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_carriage.h"

// FOR ft_lstdelone and ft_lstdell need signature: void ft_...(void* , size_t )


//void		carriage_destroy(t_carriage **self)
//{
//	ft_memdel((void **)self);
//	return;
//}


void		carriage_destroy(void *self, size_t size)
{
    free(self);
    return;
}
