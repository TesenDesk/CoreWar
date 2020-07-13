/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_vm_params_parse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 18:43:16 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/13 18:54:56 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_vm_params.h"

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

static int				prvt_vm_params_flag_name_done(t_vm_params *self,
														char *param)
{
	prvt_vm_params_set_file_name_with_id(self, param);
	return (FLAG_FILE_CODE);
}

void					prvt_vm_params_parse(t_vm_params *self, char **params)
{
	static t_sm_parser	vtable[NBR_OF_VIRTUAL_METHODS] = {
		prvt_vm_params_init,
		prvt_vm_params_flag_name,
		prvt_vm_params_flag_name_done,
		prvt_vm_params_flag_cycles,
		prvt_vm_params_flag_verbose,
		prvt_vm_params_dump_cycles,
	};
	int					arg_type;

	arg_type = NO_FLAG_CODE;
	if (!(*params))
		raise(__FILE__, __LINE__, EBADPLAYERNAME);
	while (*params)
	{
		arg_type = vtable[self->state](self, *params);
		prvt_vmp_state(self, arg_type);
		++params;
	}
}
