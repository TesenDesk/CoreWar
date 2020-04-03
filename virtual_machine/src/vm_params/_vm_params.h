/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _vm_params.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:15:50 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/04 00:05:47 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _VM_PARAMS_H
# define _VM_PARAMS_H

#include "libft.h"
#include "error.h"
#include "vm_params.h"

typedef struct s_player	t_player;

typedef struct			s_vm_params
{
	int				state;
	int				is_set_dump;
	int				nb_cycles;
	t_list			*id_player_head;
	t_list			*no_id_player_head;
}						t_vm_params;


#endif