/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_params_xtor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:27:54 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/06 00:37:52 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm_params.h"

void					vm_params_add_player_node(t_vm_params *self,
							char *file_name)
{
	t_list				*new_node;

	if ((new_node = ft_lstnew((void *)file_name, ft_strlen(file_name))) == NULL)
		raise(__FILE__, __LINE__, ENOMEMORY);
	ft_lstadd(&self->id_player_head, new_node);
	return;
}

static void				_vm_params_set_player_name(t_vm_params *self, char *params)
{
	int					player_name;
	t_vmp_player		*player;
	
	if (ft_strint_ou_flow(params, player_name) == FAILURE)
		raise(__FILE__, __LINE__, EINTOUFLOW);
	player = vmp_player_ctor(player_name, PFILE_MOCK);
	vm_params_add_player_name_node(self, player);
	return;
}

static void				_vm_params_set_file_name_with_id(t_vm_params *self,
							char *file_name)
{
	t_vmp_player		*player;

	player = (t_vmp_player *)self->id_player_head->content;
	vmp_utils_check_if_file_is_available(file_name);
	vmp_player_set_file_name(player, file_name);
	return;
}

static void				_vm_params_set_file_name_without_id(t_vm_params *self,
							char *file_name)
{
	t_vmp_player		*player;

	player = vmp_player_ctor(PNAME_MOCK, file_name);
	vmp_utils_check_if_file_is_available(file_name);
	vm_params_add_player_node(self, player);
	return;
}

static void				_vm_params_set_nbr_cycles(t_vm_params *self,
							char *params)
{
	if (ft_strint_ou_flow(*params, self->nb_cycles) == FAILURE)
		raise(__FILE__, __LINE__, EINTOUFLOW);
	self->is_set_dump == TRUE;
	return;
}

static void				_vm_params_set_is_dump(t_vm_params *self, char *params)
{
	self->is_set_dump = TRUE;
	(void)params;
	return;
}

static void				_vm_params_parse(t_vm_params *self, char **params)
{
	int					curr_player_name;
	int					state;
	static t_sm_parser	vtable[] =
	{
		_vm_params_set_is_dump,
		_vm_params_set_player_name,
		_vm_params_set_file_name_without_id,
		_vm_params_set_nbr_cycles,
		_vm_params_set_file_name_with_id,
	};

	while ((state = vmp_state(*params)) != VMP_STOP)
	{
		vtable[state](self, *params);
		++(*params);
	}
	return ;
}

t_vm_params				*vm_params_xtor(int argc, char *argv[])
{
	t_vm_params			*self;

	if (argc < 2)
		raise(__FILE__, __LINE__, EINVALARG);
	_vm_params_parse(self, argv);
	return (self);
}