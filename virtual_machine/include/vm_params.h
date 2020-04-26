/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_params.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita_toropov <nikita_toropov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:10:20 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/26 21:40:12 by nikita_toro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_PARAMS_H
# define VM_PARAMS_H

typedef struct s_vm_params	t_vm_params;

t_vm_params		*vm_params_new(int argc, char *argv[]);
void			vm_params_destroy(t_vm_params **self);

void			vm_params_destroy_players_lists(t_vm_params *params);
int				vm_params_nb_players(t_vm_params *params);
void			*vm_params_fill_and_sort_array_of_players(t_vm_params *self,
					t_arena *arena);
void			vm_params_add_player_name_node(t_vm_params *self,
					t_vmp_player *player);

#endif
