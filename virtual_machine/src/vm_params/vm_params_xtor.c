/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_params_xtor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:27:54 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/05 20:51:19 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm_params.h"

void				vm_params_add_player_node(t_vm_params *self,
						char *file_name)
{
	t_list			*new_node;

	if ((new_node = ft_lstnew((void *)file_name, ft_strlen(file_name))) == NULL)
		raise(__FILE__, __LINE__, ENOMEMORY);
	ft_lstadd(&self->id_player_head, new_node);
	return;
}

static void			_set_player_name(t_vm_params *self, char **params)
{
	int				player_name;
	char			*file_name;
	t_vmp_player	*player;
	
	if (ft_strint_ou_flow(*params, player_name) == FAILURE)
		raise(__FILE__, __LINE__, EINTOUFLOW);
	file_name = PFILE_MOCK;
	player = vmp_player_ctor(player_name, file_name);
	vm_params_add_player_name_node(self, player);
	return;
}

static void			_set_file_name_with_id(t_vm_params *self, char **params)
{
	char			*file_name;
	t_vmp_player	*player;

	file_name = *params;
	player = (t_vmp_player *)self->id_player_head->content;
	vmp_utils_check_if_file_is_available(file_name);
	vmp_player_set_file_name(player, file_name);
	return;
}

static void			_set_file_name_without_id(t_vm_params *self, char **params)
{
	int				player_name;
	char			*file_name;
	t_vmp_player	*player;

	player_name = PNAME_MOCK;
	file_name = *params;
	player = vmp_player_ctor(player_name, file_name);
	vmp_utils_check_if_file_is_available(*params);
	vm_params_add_player_node(self, player);
	return;
}

static void			_set_nbr_cycles(char **params)
{

	return;
}

typedef (*t_sm_parser)(t_vm_params *self, char **params);

static t_sm_parser	vtable[] =
{
	_set_file_name_with_id,
	_set_file_name_without_id,
	_set_nbr_cycles,
	_set_player_name
};

static void			_vm_params_parse(t_vm_params *self, char **params)
{
	int				curr_player_name;
	int				state;

	while ((state = vmp_state(*params)) != VMP_STOP)
		vtable[state](self, params);
	return ;
}

t_vm_params			*vm_params_xtor(int argc, char *argv[])
{
	t_vm_params		*self;

	if (argc < 2)
		raise(__FILE__, __LINE__, EINVALARG);
	_vm_params_parse(self, argv);
	return (self);
}