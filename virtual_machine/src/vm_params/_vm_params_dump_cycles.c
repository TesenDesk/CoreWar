#include "_vm_params.h"

int 				_vm_params_dump_cycles(t_vm_params *self, char *param)
{
	long long num;
	num = ft_atol(param);
	if (!(ft_arg_is_num(param)) || num < 0)
		raise(__FILE__, __LINE__, ENOARGVAL);
	self->dump_cycles = num;
	return (FLAG_NUM_CODE);

}