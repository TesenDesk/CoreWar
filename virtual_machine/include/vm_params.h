/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_params.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:10:20 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/07 17:00:13 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_PARAMS_H
# define VM_PARAMS_H

typedef struct s_vm_params	t_vm_params;

t_vm_params		*vm_params_ctor(int argc, char *argv[]);
void			vm_params_dtor(t_vm_params **self);

void			vm_params_destroy_players_lists(t_vm_params *params);
int				vm_params_nb_players(t_vm_params *params);
void			*vm_params_fill_and_sort_array_of_players(t_vm_params *self,
					t_arena *arena);
void			vm_params_add_player_name_node(t_vm_params *self,
					t_vmp_player *player);
					
#endif
