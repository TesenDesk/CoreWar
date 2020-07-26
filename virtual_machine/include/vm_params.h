/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_params.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:10:20 by yurezz            #+#    #+#             */
/*   Updated: 2020/07/26 16:07:28 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_PARAMS_H
# define VM_PARAMS_H

# include "vmp_player.h"
# include "arena.h"

typedef struct s_vm_params	t_vm_params;

t_vm_params		*vm_params_new(int argc, char *argv[]);
void			vm_params_destroy(t_vm_params **self);

void			vm_params_destroy_players_lists(t_vm_params *params);
int				vm_params_nb_players(t_vm_params *params);
void			vm_params_fill_and_sort_array_of_players(t_vm_params *self,
					t_arena *arena);
void			vm_params_add_p_name_node(t_vm_params *self,
					t_vmp_player *player);
int				vm_params_dump_cycles(t_vm_params *self);
int				vm_params_verbosity_lvl(t_vm_params *self);
void			vm_params_destroy(t_vm_params **self);

#endif
