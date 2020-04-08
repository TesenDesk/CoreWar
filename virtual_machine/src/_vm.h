/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _vm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:22:30 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 22:40:01 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _VM_H
# define _VM_H

# include "libft.h"
# include "errors.h"
# include "vm.h"

/*
**	Limit individual processes in the allocated memory.
** 4 gibytes are all. Suppose that the program needs to have up to 256
** processes, the maximum for each is limited by this number.
*/

# define MAX_PROC_RAM		0xFFFFFF

typedef struct s_errors t_errors;
typedef struct s_vm_params t_params;
typedef struct s_arena t_arena;
typedef struct s_carriage t_carriage;

typedef struct	s_vm
{
	t_params	*params;
	t_arena		*arena;
	t_list		*carriage_head;
}				t_vm;

t_vm		*_vm_new(int argc, char *argv[]);
void		_vm_destroy(t_vm **self);

#endif
