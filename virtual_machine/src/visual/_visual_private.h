
#ifndef VISUAL_PRIVATE_H
#define VISUAL_PRIVATE_H
#include "libft.h"
#include "visual.h"


//static int	get_live_color(t_player *player)
//{
//	int32_t index;
//
//	index = ((player->id - 1) % MAX_PLAYER_ID) + 1;
//	if (index == MIN_PLAYER_ID)
//		return (COLOR_PAIR(LIVE_GREEN) | A_BOLD);
//	else if (index == MIN_PLAYER_ID + 1)
//		return (COLOR_PAIR(LIVE_YELLOW) | A_BOLD);
//	else if (index == MIN_PLAYER_ID + 2)
//		return (COLOR_PAIR(LIVE_RED) | A_BOLD);
//	else
//		return (COLOR_PAIR(LIVE_CYAN) | A_BOLD);
//}
//
//int			get_attribute(t_vm *vm, t_attr *attribute, ssize_t cycles)
//{
//	if (cycles != vm->cycles
//	    && vm->cycles_to_die > 0
//	    && attribute->wait_cycles_live > 0)
//		attribute->wait_cycles_live--;
//	if (cycles != vm->cycles
//	    && vm->cycles_to_die > 0
//	    && attribute->wait_cycles_store > 0)
//		attribute->wait_cycles_store--;
//	if (attribute->wait_cycles_live)
//		return (get_live_color(attribute->player_live));
//	else if (attribute->wait_cycles_store)
//		return (g_colors_players[attribute->index] | A_BOLD);
//	else
//		return (g_colors_players[attribute->index]);
//}
//
//static int g_colors_players[15] = {
//		COLOR_PAIR(GRAY),
//		COLOR_PAIR(GREEN),
//		COLOR_PAIR(YELLOW),
//		COLOR_PAIR(RED),
//		COLOR_PAIR(CYAN),
//		COLOR_PAIR(GRAY_CURSOR),
//		COLOR_PAIR(GREEN_CURSOR),
//		COLOR_PAIR(YELLOW_CURSOR),
//		COLOR_PAIR(RED_CURSOR),
//		COLOR_PAIR(CYAN_CURSOR)
//};

/*
** Attribute
*/

/*
** index             — index of attribute
** wait_cycles_store — cycles to wait for st and sti operators
** wait_cycles_live  — cycles to wait for live operator
** player_live       — pointer to player which executed live operator
*/

//typedef struct		s_attr
//{
//	int32_t			index;
//	ssize_t			wait_cycles_store;
//	ssize_t			wait_cycles_live;
//	t_player		*player_live;
//}					t_attr;

//typedef struct          s_color_mapcell
//{
//	int                 player_index;
//	int                 cell_index;
//
//}                       t_color_mapcell;


/*
** Visualizer
*/

/*
** is_running    — status of corewar execution (is running or paused)
** speed         — speed of execution (cycles per second)
** win_arena     — window of arena
** win_info      — window of info bar
** win_help      — window of help menu
** cursor_pos    — position of cursor that draws at windows
** map           — map of attributes
** button        — button which was pressed
** time          — time stamp
** aff_symbol    — symbol that aff operator printed
** aff_player    — player which executed aff operator
** sounds        — sounds are on/off
** display_help  — help menu is displayed, or not?
*/

//typedef struct		s_vs
//{
//	t_bool			is_running;
//	int				speed;
//	WINDOW			*win_arena;
//	WINDOW			*win_info;
//	WINDOW			*win_help;
//	int				cursor_pos;
//	t_attr			map[MEM_SIZE];
//	int				button;
//	clock_t			time;
//	char			aff_symbol;
//	t_player		*aff_player;
//	t_bool			sounds;
//	t_bool			display_help;
//}					t_vs;

/*
** Functions
*/

/*
** Init
*/

//t_vs				*init_vs(void);
//
///*
//** Execute
//*/
//
//void				exec_vs(t_vm *vm);
//
///*
//** Configure
//*/
//
//void				configure_vs(t_vm *vm);
//
///*
//** Colors
//*/
//
//void				init_colors(void);
//
//int					get_attribute(t_vm *vm, t_attr *attribute, ssize_t cycles);
//
///*
//** Draw
//*/
//
//void				draw(t_vm *vm);
//
//void				draw_info(t_vm *vm);
//
//void				draw_help(t_vm *vm);
//
//void				draw_exec_status(t_vm *vm);
//
//void				draw_sounds_status(t_vm *vm);
//
//void				draw_help_status(t_vm *vm);
//
///*
//** Cursor
//*/
//
//void				draw_cursor(t_vm *vm, t_cursor *cursor);
//
//void				clear_cursor(t_vm *vm, t_cursor *cursor);
//
///*
//** Bar
//*/
//
//void				draw_lives_bar(t_vm *vm, t_bool current);
//
///*
//** Sound
//*/
//
//void				play_death_sound(t_vm *vm);
//
//void				play_victory_sound(t_vm *vm);
//
///*
//** Free
//*/
//
//void				free_vs(t_vs **vs);
//
///*
//** Operators' Utils
//*/
//
//void				update_map(t_vm *vm,
//                               t_cursor *cursor,
//                               int32_t addr,
//                               int32_t size);
//
///*
//** Utils
//*/
//
//void				clear_name(char *name);
//
//clock_t				calc_time_delay(t_vm *vm);
//
#endif
