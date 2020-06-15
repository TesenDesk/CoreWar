/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:04:08 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 23:13:27 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

enum			e_vm_singleton
{
	VM_INSTANTIATE,
	VM_DESTRUCT,
};

typedef struct s_vm	t_vm;

t_vm			*vm_singleton(int instantiation_status, int argc, char *argv[]);
void 		    vm_play(t_vm *self);
int             vm_cycles_counter(t_vm *self);
void            vm_increase_num_of_live_ops(t_vm *self);



#endif
