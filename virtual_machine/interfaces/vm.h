/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:04:08 by yurezz            #+#    #+#             */
/*   Updated: 2020/08/08 16:37:26 by ftothmur         ###   ########.fr       */
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

typedef struct s_vm			t_vm;

typedef struct s_arena		t_arena;
typedef struct s_wins		t_wins;
typedef void				(*vm_play_fptr)(t_vm *);

t_vm			*vm_singleton(int instantiation_status, int argc, char *argv[]);
void			vm_play(t_vm *self);
void			vm_play_visual(t_vm *self);
int				vm_global_counter();
void			vm_increase_num_of_live_ops();
void			vm_add_new_carriage_node(t_list *new_node);
int				vm_num_of_carriages_and_increase();
int				vm_verbosity_lvl();
void			vm_carriage_list_destruct(t_list **carriage_list);

t_arena			*vm_get_arena(t_vm *self);
t_wins			*vm_get_wins(t_vm *self);
unsigned int	vm_get_cycles_counter(t_vm *self);
int				vm_get_global_counter(t_vm *self);
unsigned int	vm_get_cycles_to_die(t_vm *self);
int				vm_get_speed(t_vm *self);

// TODO: перенести # include "ft_printf.h" в приватный интерфейс.
#endif
