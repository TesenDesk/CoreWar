/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:04:08 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/03 19:06:44 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

enum			e_vm_xtor
{
	VM_INSTANTIATE,
	VM_DESTRUCT,
};

typedef struct s_vm	t_vm;

t_vm			*vm_singleton(int instantiation_status, int argc, char **argv);

#endif
