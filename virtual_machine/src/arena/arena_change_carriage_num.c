/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_get_carriage_num.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 15:55:01 by jjerde            #+#    #+#             */
/*   Updated: 2020/08/09 16:00:03 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_arena.h"

void	arena_change_carriage_num(t_arena *self, int index, int change_by)
{
	self->carriage_num[index] += change_by;
}
