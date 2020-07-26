/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_vm.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 16:56:05 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/26 16:07:28 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRVT_VM_H
# define PRVT_VM_H

# include "libft.h"
# include "errors.h"
# include "vm.h"
# include "vm_params.h"
# include "carriage.h"
# include "op.h"
# include "arena.h"

# define MAX_PROC_RAM		0xFFFFFF

typedef struct				s_vm
{
	t_vm_params				*params;
	t_arena					*arena;
	t_list					*carriage_head;
	int						cycles_to_die;
	int						cycles_to_dump;
	int						cycles_counter;
	int						global_counter;
	int						num_of_live_ops;
	int						num_checks;
	int						num_of_carriages;
	int						verbosity_lvl;
}							t_vm;

t_vm						*prvt_vm_new(int argc, char **argv);
void						prvt_vm_destroy(t_vm **self);

#endif
