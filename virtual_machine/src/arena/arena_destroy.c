/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 23:05:26 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 23:05:52 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_arena.h"

void				arena_destroy(t_arena **self)
{
	player_destroy(&(*self)->players);
	ft_memdel((void **)self);
	return;
}
