/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:04:08 by yurezz            #+#    #+#             */
/*   Updated: 2020/07/13 12:45:53 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "ft_printf.h"

enum			e_vm_singleton
{
	VM_INSTANTIATE,
	VM_DESTRUCT,
};

typedef struct s_vm	t_vm;

typedef void			(*vm_play_fptr)(t_vm *);

t_vm			*vm_singleton(int instantiation_status, int argc, char *argv[]);
void			vm_play(t_vm *self);
void			vm_play_visual(t_vm *self);
int				vm_global_counter();
void			vm_increase_num_of_live_ops();
void			vm_add_new_carriage_node(t_list *new_node);
int				vm_num_of_carriages_and_increase();
int				vm_verbosity_lvl();
void			vm_carriage_list_destruct(t_list **carriage_list);

#endif
