/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_xtor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:29:47 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/06 21:55:33 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_arena.h"
stadic void			arena_ctor_precondition(void)
{
	if (MEM_SIZE <= 0 || CHAMP_MAX_SIZE <= 0 || REG_NUMBER <= 0)
	return;
}

void				arena_ctor(t_vm_params *params)
{
	arena_ctor_precondition();
Число игроков <= MAX_PLAYERS
	return;
}