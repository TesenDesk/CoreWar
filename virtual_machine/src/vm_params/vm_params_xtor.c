/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_params_xtor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:27:54 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/05 11:46:51 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm_params.h"

static void			_check_if_file_is_available(char *file_name)
{
	int				fd;

	if ((fd = open(file_name, O_RDONLY)) == FAILURE)
		raise(__FILE__, __LINE__, EBADFILENAME);
	if (read(fd, NULL, 0) == FAILURE)
	{
		if (close(fd) == FAILURE)
			raise(__FILE__, __LINE__, ECANNOTCLOSE);
		raise(__FILE__, __LINE__, ECANNOTREAD);
	}
	if (close(fd) == FAILURE)
		raise(__FILE__, __LINE__, ECANNOTCLOSE);
	return;
}
void				vm_params_add_player_node(t_vm_params *self,
						char *file_name)
{
	t_list			*new_node;

	if ((new_node = ft_lstnew((void *)file_name, ft_strlen(file_name))) == NULL)
		raise(__FILE__, __LINE__, ENOMEMORY);
	ft_lstadd(self->id_player_head, new_node);
	return;
}

static void			_set_player_name(t_vm_params *self, char **params)
{
	t_parsed_player	*p;

	p = parsed_player_ctor(PARAMS_CAP, *params);
	vm_params_add_player_name_node(self, p);
	return;
}

static void			_set_file_name_with_id(t_vm_params *self, char **params)
{
	_check_if_file_is_available(*params);
	vm_params_set_player_file_name(self, *params);
	return;
}

static void			_set_file_name_without_id(t_vm_params *self, char **params)
{
	t_parsed_player	*p;

	p = parsed_player_ctor(*params, PLAYER_NAME_CAP);
	_check_if_file_is_available(*params);
	vm_params_add_player_node(self, p);
	return;
}

static void			_set_nbr_cycles(char **params)
{

	return;
}

static void			_vm_params_parse(t_vm_params *self, char **params)
{
	int				curr_player_name;
	int				state;

	while ((state = vmp_state(*params)) != VMP_STOP)
		vmp_vtable(state, params);
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