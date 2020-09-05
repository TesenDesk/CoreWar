/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 14:47:50 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/29 19:01:03 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

typedef struct s_vm				t_vm;
typedef struct s_wins			t_wins;

typedef struct					s_color_mapcell
{
	int					player_index;
	int					cell_index;
	int					store_index;
}								t_color_mapcell;

t_wins							*init_wins(void);
void							draw_arena(t_vm *vm);
void							init_curses(void);
void							erase_windows(t_vm *vm);
void							print_windows(t_vm *vm);
void							process_keys(t_vm *self);
void							print_winner_visual(t_vm *vm);

#endif
