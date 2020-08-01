/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:42:18 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/01 13:27:42 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_visual.h"

/*
** box(local_win, ' ', ' '); : This won't produce the desired
** result of erasing the window. It will leave it's four corners
** and so an ugly remnant of window.
**
** wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
** The parameters taken are
** 1. win: the window on which to operate
** 2. ls: character to be used for the left side of the window
** 3. rs: character to be used for the right side of the window
** 4. ts: character to be used for the top side of the window
** 5. bs: character to be used for the bottom side of the window
** 6. tl: character to be used for the top left corner of the window
** 7. tr: character to be used for the top right corner of the window
** 8. bl: character to be used for the bottom left corner of the window
** 9. br: character to be used for the bottom right corner of the window
**
** wrefresh(local_win);
** delwin(local_win);
*/

void		destroy_win(WINDOW *local_win)
{
	wborder(local_win, " ", " ", " ", " ", " ", " ", " ", " ");
	wrefresh(local_win);
	delwin(local_win);
}
