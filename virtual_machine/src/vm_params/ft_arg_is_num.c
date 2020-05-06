//
// Created by ikira on 06.05.2020.
//
#include "_vm_params.h"


int 				ft_arg_is_num(char *param)
{
	if (*param == '+' || *param == '-')
		++param;
	while (ft_isdigit(*param))
		++param;
	return (!(*param));
}
