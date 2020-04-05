/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _vm_params.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:15:50 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/06 01:19:00 by yurezz           ###   ########.fr       */
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

typedef (*t_sm_parser)(t_vm_params *self, char **params);

typedef struct					s_vm_params
{
	t_vmp_state		*state;
	int				is_set_dump;
	int				nb_cycles;
	t_list			*id_player_head;
	t_list			*no_id_player_head;
}								t_vm_params;
void		_vm_params_parse(t_vm_params *self, char **params);
void		_vm_params_add_player_node(t_vm_params *self, char *file_name);

void		_vm_params_set_player_name(t_vm_params *self,
				char *player_name_str);
void		_vm_params_set_file_name_with_id(t_vm_params *self,
				char *file_name);
void		_vm_params_set_file_name_without_id(t_vm_params *self,
				char *file_name);
void		_vm_params_set_nbr_cycles(t_vm_params *self, char *nbr_sycles_str);
void		_vm_params_set_is_dump(t_vm_params *self, char *useless);
void		_vm_params_set_mock(t_vm_params *never_passed, char *usless);

#endif
