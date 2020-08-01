/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_curses.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:53:41 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/01 13:24:47 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_visual.h"

/*
**	initscr();			Start curses mode
**	cbreak();			Line buffering disabled, Pass on
**						everty thing to me
*/

void	init_curses(void)
{
	initscr();
	cbreak();
	if (has_colors() == FALSE)
	{
		endwin();
		ft_printf("Your terminal does not support color\n");
		exit(1);
	}
	start_color();
}
