/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_params_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:27:54 by yurezz            #+#    #+#             */
/*   Updated: 2020/07/26 16:07:28 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_vm_params.h"

static void			prvt_vm_params_new_precondition_check(int argc)
{
	if (argc < 1)
		ft_raise(__FILE__, __LINE__, EINVALARG);
	return ;
}

static void			prvt_vm_params_new_postcondition_check(t_vm_params *self)
{
	if (self->nb_players > MAX_PLAYERS)
		ft_raise(__FILE__, __LINE__, EMANYPLAYERS);
	if (
			self->nb_players <= 0 ||
			(self->noid_player_head || self->id_player_head) == FALSE)
		ft_raise(__FILE__, __LINE__, ENOPLAYERS);
	if (self->nb_players > REG_SIZE * (BITS_AT_BYTE / 2) - 1)
		ft_raise(__FILE__, __LINE__, EDATALOSS);
	return ;
}

t_vm_params			*vm_params_new(int argc, char *argv[])
{
	t_vm_params		*self;

	prvt_vm_params_new_precondition_check(argc);
	if ((self = (t_vm_params *)ft_memalloc(sizeof(*self))) == NULL)
		ft_raise(__FILE__, __LINE__, ENOMEMORY);
	self->dump_cycles = -1;
	prvt_vm_params_parse(self, argv);
	prvt_vm_params_new_postcondition_check(self);
	return (self);
}
