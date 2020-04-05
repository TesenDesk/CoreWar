/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _vm_params.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:15:50 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/05 20:30:16 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _VM_PARAMS_H
# define _VM_PARAMS_H

# include "libft.h"
# include "errors.h"
# include "vm_params.h"
# include "vmp_state.h"
# include "vmp_utils.h"
# include "vmp_player.h"

typedef struct s_player			t_player;
typedef struct s_vmp_state		t_vmp_state;
typedef struct s_parsed_player	t_parsed_player;

typedef struct					s_vm_params
{
	t_vmp_state		*state;
	int				is_set_dump;
	int				nb_cycles;
	t_list			*id_player_head;
	t_list			*no_id_player_head;
}								t_vm_params;

#endif