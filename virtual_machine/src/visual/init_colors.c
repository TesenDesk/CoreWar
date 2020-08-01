/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:42:58 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/01 12:43:20 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_visual.h"

void	init_colors(void)
{
	init_color(COLOR_GRAY, 355, 355, 355);
	init_pair(P_1_HOME, COLOR_RED, COLOR_BLACK);
	init_pair(P_2_HOME, COLOR_YELLOW, COLOR_BLACK);
	init_pair(P_3_HOME, COLOR_GREEN, COLOR_BLACK);
	init_pair(P_4_HOME, COLOR_BLUE, COLOR_BLACK);
	init_pair(P_1_L_HOME, COLOR_BLACK, COLOR_RED);
	init_pair(P_2_L_HOME, COLOR_BLACK, COLOR_YELLOW);
	init_pair(P_3_L_HOME, COLOR_BLACK, COLOR_GREEN);
	init_pair(P_4_L_HOME, COLOR_BLACK, COLOR_BLUE);
	init_pair(P_1_L_OUT, COLOR_WHITE, COLOR_RED);
	init_pair(P_2_L_OUT, COLOR_WHITE, COLOR_YELLOW);
	init_pair(P_3_L_OUT, COLOR_WHITE, COLOR_GREEN);
	init_pair(P_4_L_OUT, COLOR_WHITE, COLOR_BLUE);
	init_pair(P_1_L_WIN, COLOR_CYAN, COLOR_RED);
	init_pair(P_2_L_WIN, COLOR_CYAN, COLOR_YELLOW);
	init_pair(P_3_L_WIN, COLOR_CYAN, COLOR_GREEN);
	init_pair(P_4_L_WIN, COLOR_CYAN, COLOR_BLUE);
	init_pair(B_INFO, COLOR_CYAN, COLOR_BLACK);
	init_pair(NEUTRAL_COL, COLOR_GRAY, COLOR_BLACK);
}
