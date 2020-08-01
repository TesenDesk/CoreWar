/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_newwin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:39:34 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/01 13:28:34 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_visual.h"

WINDOW		*create_newwin(int height, int width, int starty, int startx)
{
	WINDOW	*local_win;

	local_win = newwin(height, width, starty, startx);
	return (local_win);
}
