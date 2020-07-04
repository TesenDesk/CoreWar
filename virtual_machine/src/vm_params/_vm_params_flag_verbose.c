#include "_vm_params.h"

int 				_vm_params_flag_verbose(t_vm_params *self, char *param)
{
	long long num;

	num = ft_atol(param);
	if (!(ft_arg_is_num(param)))
		raise(__FILE__, __LINE__, ENOARGVAL);
	self->verbosity_lvl = num;
	return (FLAG_NUM_CODE);
}