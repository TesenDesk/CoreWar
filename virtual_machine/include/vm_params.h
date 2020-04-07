/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_params.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:10:20 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/07 13:10:42 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_PARAMS_H
# define VM_PARAMS_H

typedef struct s_vm_params	t_vm_params;

t_vm_params		*vm_params_ctor(int argc, char *argv[]);
void			vm_params_dtor(t_vm_params **self);

void			vm_params_destroy_players(t_vm_params *params);
int				vm_params_nb_players(t_vmp_player *params);

#endif
