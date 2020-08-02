/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_visual.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:14:40 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/02 12:13:04 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRVT_VISUAL_H
# define PRVT_VISUAL_H

# include "libft.h"
# include "visual.h"
# include "op.h"
# include "../arena/prvt_arena.h"
# include "../_vm.h"
# include "../carriage/prvt_carriage.h"
# include "../arena/player/prvt_player.h"
# include "../vm_params/prvt_vm_params.h"
# include "op.h"
# include <ncurses.h>

# define EXTERNAL_COLOR_OFFSET	4
# define COLOR_GRAY				8

# define P_1_HOME				1
# define P_2_HOME				2
# define P_3_HOME				3
# define P_4_HOME				4
# define P_1_L_HOME				5
# define P_2_L_HOME				6
# define P_3_L_HOME				7
# define P_4_L_HOME				8
# define P_1_L_OUT				9
# define P_2_L_OUT				10
# define P_3_L_OUT				11
# define P_4_L_OUT				12
# define P_1_L_WIN				13
# define P_2_L_WIN				14
# define P_3_L_WIN				15
# define P_4_L_WIN				16
# define B_INFO					17
# define NEUTRAL_COL			18

# define HOME_OFFSET			4
# define OUT_OFFSET				8

typedef struct					s_wins
{
	WINDOW					*arena;
	WINDOW					*info;
	WINDOW					*champ;
	WINDOW					*win;
//	WINDOW					*help;
}								t_wins;

void		print_winner_visual(t_vm *vm);
void		print_windows(t_vm *vm);
void		init_curses(void);
void		init_colormap(t_arena *arena, t_vm *vm, int ofset_outer);
void		init_colors(void);
t_wins		*init_wins(void);
void		process_keys(t_vm *self);
WINDOW		*create_newwin(int height, int width, int starty, int startx);
int			chose_color(t_arena *arena, int index, t_vm *vm, int i);
void		draw_basic_info(t_vm *vm);
void		draw_champ_info(t_vm *vm);
void		draw_arena(t_vm *vm);
static void	rebuild_color_map_util(t_arena *arena, t_list *iter, int *index);
void		erase_windows(t_vm *vm);
void		destroy_win(WINDOW *local_win);

#endif
