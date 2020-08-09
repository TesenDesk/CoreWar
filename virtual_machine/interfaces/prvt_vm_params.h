/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_vm_params.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:15:50 by yurezz            #+#    #+#             */
/*   Updated: 2020/07/04 17:17:13 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRVT_VM_PARAMS_H
# define PRVT_VM_PARAMS_H

# include "libft.h"
# include "errors.h"
# include "op.h"
# include "vm_params.h"
# include "vmp_player.h"
# include "player.h"
# include "arena.h"
# include "vmp_player.h"

# define P_SHORT_NAME	"-n"
# define P_LONG_NAME	"-name"
# define P_SHORT_DUMP	"-d"
# define P_LONG_DUMP	"-dump"

# define FLAG_CYCLE		"-s"
# define FLAG_VERB		"-v"
# define FLAG_BINARY	"-b"
# define FLAG_STEALTH	"-stealth"
# define FLAG_NCURSES	"-curses"

# define USAGE_STR		"fix later"

enum	e_t_paramcodes
{
	NO_FLAG_CODE = 0,
	FLAG_NAME_CODE,
	FLAG_CYCLE_CODE,
	FLAG_VERBOSE_CODE,
	FLAG_DUMP_CODE,
	FLAG_BINARY_CODE,
	FLAG_STEALTH_CODE,
	FLAG_NCURSES_CODE,
	FLAG_NUM_CODE,
	FLAG_FILE_CODE,
	FLAG_UNDEF,
};

enum					e_vmp_states
{
	VMP_STOP = -1,
	VMP_INITIAL,
	VMP_SET_PNAME,
	VMP_SET_PNAME_DONE,
	VMP_SET_CYCLES,
	VMP_SET_VERB,
	VMP_SET_DUMP,
	NBR_OF_VIRTUAL_METHODS,
};

typedef struct		s_vm_params
{
	int				is_set_dump;
	int				nb_cycles;
	int				dump_cycles;
	int				ncurses;
	int				verbosity_lvl;
	int				stealth;
	int				binary;
	int				state;
	t_list			*id_player_head;
	t_list			*noid_player_head;
	int				nb_players;
}					t_vm_params;

typedef int	(*t_sm_parser)(t_vm_params *self, char *params);

void				prvt_vm_params_parse(t_vm_params *self, char **params);
void				prvt_vm_params_add_unnamed_player_node(t_vm_params *self,
						t_vmp_player *player);
void				prvt_vm_params_add_named_player_node(t_vm_params *self,
						t_vmp_player *player);
void				prvt_vm_params_set_p_name(t_vm_params *self,
						int p_name);
void				prvt_vm_params_set_file_name_with_id(t_vm_params *self,
						char *file_name);
void				prvt_vm_params_set_file_name_without_id(t_vm_params *self,
						char *file_name);
int					prvt_vm_params_init(t_vm_params *self, char *param);
int					prvt_vm_params_flag_name(t_vm_params *self, char *param);
int					prvt_vm_params_flag_cycles(t_vm_params *self, char *param);
int					prvt_vm_params_dump_cycles(t_vm_params *self, char *param);
int					prvt_vm_params_flag_verbose(t_vm_params *self, char *param);
int					ft_arg_is_num(char *param);

#endif
