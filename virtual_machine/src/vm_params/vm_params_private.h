/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_params_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:15:50 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/03 18:39:42 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_PARAMS_PRIVATE_H
# define VM_PARAMS_PRIVATE_H

#include "libft.h"
#include "error.h"
#include "vm_params.h"

typedef struct s_player	t_player;

typedef struct			s_vm_params
{
	int				is_set_dump;
	int				nb_cycles;
	t_list			*id_player_head;
	t_list			*no_id_player_head;
}						t_vm_params;


#endif