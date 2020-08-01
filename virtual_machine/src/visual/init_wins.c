/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:40:21 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/01 13:18:19 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_visual.h"

t_wins			*init_wins(void)
{
	t_wins		*wins;

	if (!(wins = ft_memalloc(sizeof(t_wins))))
		exit(-1);
	if (!(wins->arena = create_newwin(SQRT_MAP + 2, SQRT_MAP * 3 + 2, 1, 1)))
		exit(-1);
	if (!(wins->info = create_newwin(9, 75, 1, SQRT_MAP * 3 + 4)))
		exit(-1);
	if (!(wins->champ = create_newwin(14, 53, 10, SQRT_MAP * 3 + 4)))
		exit(-1);
	if (!(wins->win = create_newwin(4, 38, SQRT_MAP + 3, 1)))
		exit(-1);
	return (wins);
}
