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
	ARG_NUM,
	ARG_FILE,
};
enum 				e_t_paramcodes
{
	NO_FLAG_CODE = 0,
	FLAG_NAME_CODE,
	FLAG_CYCLE_CODE,
	FLAG_VERBOSE_CODE,
	FLAG_DUMP_CODE,
	FLAG_BINARY_CODE,
	FLAG_STEALTH_CODE,
	FLAG_NCURSES_CODE,
	FLAG_NUM_CODE,
	FLAG_FILE_CODE,
	FLAG_UNDEF,
};



static int 					flag_check(char *param) {
	if (!ft_strncmp(P_SHORT_NAME, param, 2) ||
		!ft_strncmp(P_LONG_NAME, param, 6))
		return (FLAG_NAME_CODE);
	else if (!ft_strncmp(FLAG_CYCLE, param, 2))
		return (FLAG_CYCLE_CODE);
	else if(!ft_strncmp(FLAG_VERB, param, 2))
		return (FLAG_VERBOSE_CODE);
	else if (!ft_strncmp(P_SHORT_DUMP, param, 2) ||
			!ft_strncmp(P_LONG_DUMP, param, 6))
		return (FLAG_DUMP_CODE);
	else if(!ft_strncmp(FLAG_STEALTH, param, 9))
		return (FLAG_STEALTH_CODE);
	else if(!ft_strncmp(FLAG_NCURSES, param, 8))
		return (FLAG_NCURSES_CODE);
	else if (!ft_strncmp(FLAG_BINARY, param, 2))
		return (FLAG_BINARY_CODE);
	else if (ft_arg_is_num(param))
		return (FLAG_NUM_CODE);
	return (FLAG_FILE_CODE);
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
static int 				is_numflag(int flag)
{
	return (flag >= FLAG_NAME_CODE && flag <= FLAG_VERBOSE_CODE);
}



static int				_vm_params_init(t_vm_params *self, char *param)
{
	int 				flag;

	flag = flag_check(param);
	if(flag == FLAG_STEALTH_CODE || flag == FLAG_NCURSES_CODE
	|| flag == FLAG_BINARY_CODE || flag == FLAG_DUMP_CODE) {
		_vm_params_flag_on(self, flag);
		return (flag);
	}
	else if (flag == FLAG_FILE_CODE)
		_vm_params_set_file_name_without_id(self, param);
	return (flag);
	/*
	 * какие названия файлов допустимы?
	 */

}

static int 				_vm_params_flag_name(t_vm_params *self, char *param)
{
	long long num;

	num = ft_atol(param);
	if (!(ft_arg_is_num(param)))
		raise(__FILE__, __LINE__, ENOARGVAL);
	_vm_params_set_player_name(self, num);
	return (FLAG_NUM_CODE);
}

static int 				_vm_params_flag_name_done(t_vm_params *self, char *param)
{

//	_vm_params_set_player_name(self, num);
	_vm_params_set_file_name_with_id(self, param);
	return (FLAG_FILE_CODE);
}

static int 				_vm_params_flag_cycles(t_vm_params *self, char *param)
{
	long long num;

	num = ft_atol(param);
	if (!(ft_arg_is_num(param)))
		raise(__FILE__, __LINE__, ENOARGVAL);
	self->nb_cycles = num;
	return (FLAG_NUM_CODE);

}

static int 				_vm_params_flag_verbose(t_vm_params *self, char *param)
{
	long long num;

	num = ft_atol(param);
	if (!(ft_arg_is_num(param)))
		raise(__FILE__, __LINE__, ENOARGVAL);
	self->nb_cycles = num;
	return (FLAG_NUM_CODE);

}

int 					_vmp_state(t_vm_params *self, int argtype)
{
	if (self->state == VMP_INITIAL) {
		if (argtype == FLAG_NUM_CODE)
			raise(__FILE__, __LINE__, ENOARGVAL);
		else if (argtype == FLAG_FILE_CODE || argtype == FLAG_DUMP_CODE
				 || argtype == FLAG_BINARY_CODE || argtype == FLAG_NCURSES_CODE
				 || argtype == FLAG_STEALTH_CODE)
			;
		else if (argtype == FLAG_VERBOSE_CODE)
			self->state = VMP_SET_VERB;
		else if (argtype == FLAG_CYCLE_CODE)
			self->state = VMP_SET_CYCLES;
		else if (argtype == FLAG_NAME_CODE)
			self->state = VMP_SET_PNAME;
	}
	else if(self->state == VMP_SET_CYCLES || self->state == VMP_SET_VERB) {
		if (argtype == FLAG_NUM_CODE)
			self->state = VMP_INITIAL;
		else
			raise(__FILE__, __LINE__, ENOARGVAL);
	}
	else if (self->state == VMP_SET_PNAME) {
		if (argtype == FLAG_NUM_CODE)
			self->state = VMP_SET_PNAME_DONE;
		else
			raise(__FILE__, __LINE__, ENOARGVAL);
	}
	else if (self->state == VMP_SET_PNAME_DONE)
	{
		if (argtype == FLAG_FILE_CODE)
			self->state = VMP_INITIAL;
		else
			raise(__FILE__, __LINE__, ENOARGVAL);
	}
}
//

void					_vm_params_parse(t_vm_params *self, char **params)
{
	int					curr_player_name;
	int 				arg_type;

	arg_type = NO_ARG;
	static t_sm_parser 	vtable[NBR_OF_VIRTUAL_METHODS] =
	{
			_vm_params_init,
			_vm_params_flag_name,
			_vm_params_flag_name_done,
			_vm_params_flag_cycles,
			_vm_params_flag_verbose,
	};
//	printf("\n\n\n\n\n\n\n\n\n");
	if (!(*params))
	{
		printf(USAGE_STR);
		exit(0);
	}
 	while (*params)
	{
		arg_type = vtable[self->state](self, *params);
		_vmp_state(self, arg_type);
		++params;
	}
//	printf("done\n\n\n\n\n\n\n\n");
	return ;
}
