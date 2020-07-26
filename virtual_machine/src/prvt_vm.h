/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_vm.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 16:56:05 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/13 16:56:07 by cmissy           ###   ########.fr       */
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
# include "visual.h"

# define MAX_PROC_RAM		0xFFFFFF

typedef struct				s_vm
{
	t_vm_params	*params;
	t_arena		*arena;
	t_list		*carriage_head;
	t_wins		*wins;
	char		speed;
	int			cycles_to_die;
	int			cycles_to_dump;
	int			cycles_counter;
	int			global_counter;
	int			num_of_live_ops;
	int			num_checks;
	int			num_of_carriages;
	int			verbosity_lvl;
	int			urgent_break;
	int			is_erased;
	int			key;
}							t_vm;



t_vm						*prvt_vm_new(int argc, char **argv);
void						prvt_vm_destroy(t_vm **self);

#endif
