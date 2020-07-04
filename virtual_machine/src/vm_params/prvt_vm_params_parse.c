/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_vm_params_parse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 18:43:16 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/02 18:55:48 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm_params.h"

static int				prvt_vm_params_flag_name_done(t_vm_params *self,
													char *param)
{
	_vm_params_set_file_name_with_id(self, param);
	return (FLAG_FILE_CODE);
}

static int				prvt_vmp_state(t_vm_params *self, int argtype)
{
	if (self->state == VMP_INITIAL
			&& argtype != FLAG_NUM_CODE)
	{
		if (argtype == FLAG_VERBOSE_CODE)
			self->state = VMP_SET_VERB;
		else if (argtype == FLAG_CYCLE_CODE)
			self->state = VMP_SET_CYCLES;
		else if (argtype == FLAG_NAME_CODE)
			self->state = VMP_SET_PNAME;
		else if (argtype == FLAG_DUMP_CODE)
			self->state = VMP_SET_DUMP;
	}
	else if ((self->state == VMP_SET_CYCLES || self->state == VMP_SET_VERB
			|| self->state == VMP_SET_DUMP)
			&& argtype == FLAG_NUM_CODE)
		self->state = VMP_INITIAL;
	else if (self->state == VMP_SET_PNAME
			&& argtype == FLAG_NUM_CODE)
		self->state = VMP_SET_PNAME_DONE;
	else if (self->state == VMP_SET_PNAME_DONE
			&& argtype == FLAG_FILE_CODE)
		self->state = VMP_INITIAL;
	else
		raise(__FILE__, __LINE__, ENOARGVAL);
	return (SUCCESS);
}

void					prvt_vm_params_parse(t_vm_params *self, char **params)
{
	int					urr_player_name;
	int					arg_type;
	static t_sm_parser	vtable[NBR_OF_VIRTUAL_METHODS];

	vtable[0] = prvt_vm_params_init;
	vtable[1] = prvt_vm_params_flag_name;
	vtable[2] = prvt_vm_params_flag_name_done;
	vtable[3] = _vm_params_flag_cycles;
	vtable[4] = _vm_params_flag_verbose;
	vtable[5] = _vm_params_dump_cycles;
	arg_type = NO_ARG;
	if (!(*params))
		raise(__FILE__, __LINE__, EBADPLAYERNAME);
	while (*params)
	{
		arg_type = vtable[self->state](self, *params);
		prvt_vmp_state(self, arg_type);
		++params;
	}
}
