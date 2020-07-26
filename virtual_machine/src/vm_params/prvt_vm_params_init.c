/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _vm_params_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 18:39:44 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/26 16:07:28 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_vm_params.h"

static void		prvt_vm_params_flag_on(t_vm_params *self, int flag_type)
{
	if (flag_type == FLAG_DUMP_CODE)
		self->is_set_dump = TRUE;
	else if (flag_type == FLAG_STEALTH_CODE)
		self->stealth = TRUE;
	else if (flag_type == FLAG_BINARY_CODE)
		self->binary = TRUE;
	else if (flag_type == FLAG_NCURSES_CODE)
		self->ncurses = TRUE;
}

static int		flag_check(char *param)
{
	if (!ft_strncmp(P_SHORT_NAME, param, ft_strlen(P_SHORT_NAME)) ||
			!ft_strncmp(P_LONG_NAME, param, ft_strlen(P_LONG_NAME)))
		return (FLAG_NAME_CODE);
	else if (!ft_strncmp(FLAG_CYCLE, param, ft_strlen(FLAG_CYCLE)))
		return (FLAG_CYCLE_CODE);
	else if (!ft_strncmp(FLAG_VERB, param, ft_strlen(FLAG_VERB)))
		return (FLAG_VERBOSE_CODE);
	else if (!ft_strncmp(P_SHORT_DUMP, param, ft_strlen(P_SHORT_DUMP)) ||
			!ft_strncmp(P_LONG_DUMP, param, ft_strlen(P_LONG_DUMP)))
		return (FLAG_DUMP_CODE);
	else if (!ft_strncmp(FLAG_STEALTH, param, ft_strlen(FLAG_STEALTH)))
		return (FLAG_STEALTH_CODE);
	else if (!ft_strncmp(FLAG_NCURSES, param, ft_strlen(FLAG_NCURSES)))
		return (FLAG_NCURSES_CODE);
	else if (!ft_strncmp(FLAG_BINARY, param, ft_strlen(FLAG_BINARY)))
		return (FLAG_BINARY_CODE);
	else if (ft_arg_is_num(param))
		return (FLAG_NUM_CODE);
	else if (*param == '-')
		ft_raise(__FILE__, __LINE__, FLAG_UNDEF);
	return (FLAG_FILE_CODE);
}

int				prvt_vm_params_init(t_vm_params *self, char *param)
{
	int			flag;

	flag = flag_check(param);
	if (flag == FLAG_STEALTH_CODE || flag == FLAG_NCURSES_CODE
			|| flag == FLAG_BINARY_CODE)
	{
		prvt_vm_params_flag_on(self, flag);
		return (flag);
	}
	else if (flag == FLAG_FILE_CODE)
		prvt_vm_params_set_file_name_without_id(self, param);
	return (flag);
}
