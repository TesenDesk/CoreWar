/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _vm_params_parse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita_toropov <nikita_toropov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 01:17:29 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/26 20:31:12 by nikita_toro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm_params.h"

# define P_SHORT_NAME	"-n"
# define P_LONG_NAME	"--name"
# define P_SHORT_DUMP	"-d"
# define P_LONG_DUMP	"--dump"
# define FLAG_CYCLE		"-s"
# define FLAG_VERB		"-v"
# define FLAG_BINARY	"-b"
# define FLAG_STEALTH	"--stealth"
# define FLAG_NCURSES	"--curses"

enum				e_t_argtype
{
	NO_ARG = 0,
	ARG_NUMFLUG,
	ARG_NONUMFLAG,
	ARG_FILE,
};
enum 				e_t_flagcodes
{
	NO_FLAG_CODE = 0,
	FLAG_NAME_CODE,
	FLAG_CYCLE_CODE,
	FLAG_VERBOSE_CODE,
	FLAG_DUMP_CODE,
	FLAG_BINARY_CODE,
	FLAG_STEALTH_CODE,
	FLAG_NCURSES_CODE,
};



static int 					flag_check(char *param) {
	if (ft_strncmp(P_SHORT_NAME, param, 2) ||
		ft_strncmp(P_LONG_NAME, param, 6))
		return (FLAG_NAME_CODE);

	else if (ft_strncmp(FLAG_CYCLE, param, 2))
		return (FLAG_CYCLE_CODE);
	else if(ft_strncmp(FLAG_VERB, param, 2))
		return (FLAG_VERBOSE_CODE);
	else if (ft_strncmp(P_SHORT_DUMP, param, 2) ||
			ft_strncmp(P_LONG_DUMP, param, 6))
		return (FLAG_DUMP_CODE);
	else if(ft_strncmp(FLAG_STEALTH, param, 9))
		return (FLAG_STEALTH_CODE);
	else if(ft_strncmp(FLAG_NCURSES, param, 8))
		return (FLAG_NCURSES_CODE);
}

static void				_vm_params_flag_on(t_vm_params *self, int flag_type)
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

static int				_vm_params_init_action(t_vm_params *self, char *param)
{
	int 				flag;

	flag = flag_check(param);
	if (flag == FLAG_CYCLE)
		return (VMP_SET_CYCLES);
	else if (flag == FLAG_NAME_CODE)
		return (VMP_SET_PNAME);
	else if (flag == FLAG_VERB)
		return (VMP_SET_VERB);
	else if (flag >= FLAG_DUMP_CODE)
	{
		_vm_params_flag_on(self, flag);
		return (VMP_INITIAL);
	}
	else if (ft_arg_is_num(param))
		exit(-1);
	else
	{
		_vm_params_set_file_name_without_id(self, param);
		return (VMP_INITIAL);
	}
}

static int				_vm_params_waitnum_action(t_vm_params *self, char *param)
{
	long long num;

	num = 0;
	if (!ft_arg_is_num(param))
		exit(-1);
	num = ft_atol(param);



}


void					_vm_params_parse(t_vm_params *self, char **params)
{
	int					curr_player_name;
	int					state;	
//	static int	vtable[NBR_OF_VIRTUAL_METHODS] =
//	{
//			_vm_params_init_action,
//			_vm_params_waitnum_action,
//		_vm_params_set_file_name_without_id,
//	};
//	while (state != VMP_STOP)
//	{
//		 vtable[state](self, *params);
//		state = vmp_state(int));
//		++params;
//	}
	return ;
}
