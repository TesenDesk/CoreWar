/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_get_carriage_num.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 15:02:57 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/09 15:03:00 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_arena.h"

int	arena_get_carriage_num(t_arena *self, int index)
{
	return (self->carriage_num[index]);
}
