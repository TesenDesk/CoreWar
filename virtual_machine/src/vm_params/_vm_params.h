/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _vm_params.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita_toropov <nikita_toropov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:15:50 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/26 21:40:55 by nikita_toro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _VM_PARAMS_H
# define _VM_PARAMS_H

<<<<<<< HEAD
    # include "../../../libft/libft.h" // changes by cmissy
# include "../../include/errors.h"
# include "../../include/op.h"
# include "../../include/vm_params.h"
# include "../../include/vmp_state.h"
# include "../../include/vmp_player.h"
# include "../../include/player.h"
# include "../../include/arena.h"
# include "../../include/vm_params.h"
//# include "vmp_player.h"
=======
# include "libft.h"
# include "errors.h"
# include "op.h"
# include "vm_params.h"
# include "vmp_state.h"
# include "vmp_player.h"
# include "player.h"
# include "arena.h"
# include "vm_params.h"
#include "../vmp_player/_vmp_player.h"
>>>>>>> 9e694051cb87f51b02066e202c8af78361558f3b

//typedef  void (*t_sm_parser)(t_vm_params *self, char **params);
typedef  int (*t_sm_parser)(t_vm_params *self, char *params);

# define USAGE_STR			 "Usage: ./corewar [-d N -s N -v N | -b --stealth | -n --stealth] [-a] <champion1.cor> <...>\n"
//							 "    -a        : Prints output from \"aff\" (Default is to hide it)\n"
//							 "#### TEXT OUTPUT MODE ##########################################################\n"
//							 "    -d N      : Dumps memory after N cycles then exits\n"
//							 "    -s N      : Runs N cycles, dumps memory, pauses, then repeats\n"
//							 "    -v N      : Verbosity levels, can be added together to enable several\n"
//							 "                - 0 : Show only essentials\n"
//							 "                - 1 : Show lives\n"
//							 "                - 2 : Show cycles\n"
//							 "                - 4 : Show operations (Params are NOT litteral ...)\n"
//							 "                - 8 : Show deaths\n"
//							 "                - 16 : Show PC movements (Except for jumps)\n"
//							 "#### BINARY OUTPUT MODE ########################################################\n"
//							 "    -b        : Binary output mode for corewar.42.fr\n"
//							 "    --stealth : Hides the real contents of the memory\n"
//							 "#### NCURSES OUTPUT MODE #######################################################\n"
//							 "    -n        : Ncurses output mode\n"
//							 "    --stealth : Hides the real contents of the memory\n"
//							 "################################################################################"

typedef struct					s_vm_params
{
	int				is_set_dump;
	int				nb_cycles;
	int 			ncurses;
	int 			verbosity_lvl;
	int 			stealth;
	int 			binary;
	int				state;
	t_list			*id_player_head;
	t_list			*noid_player_head;
	int				nb_players;
}								t_vm_params;

void		_vm_params_parse(t_vm_params *self, char **params);
void		_vm_params_add_unnamed_player_node(t_vm_params *self, t_vmp_player *player);
void		_vm_params_add_named_player_node(t_vm_params *self,
				void *file_name);

void		_vm_params_set_player_name(t_vm_params *self,
				 int player_name);
void		_vm_params_set_file_name_with_id(t_vm_params *self,
				char *file_name);
void		_vm_params_set_file_name_without_id(t_vm_params *self,
				char *file_name);
<<<<<<< HEAD
void		_vm_params_set_nbr_cycles(t_vm_params *self, char *nbr_cycles_str);
void		_vm_params_set_is_dump(t_vm_params *self, char *useless);
void		_vm_params_set_mock(t_vm_params *never_passed, char *usless);
=======

int 					_vmp_state(t_vm_params *self, int argtype);

int 						ft_arg_is_num(char *param);
>>>>>>> 9e694051cb87f51b02066e202c8af78361558f3b

#endif
