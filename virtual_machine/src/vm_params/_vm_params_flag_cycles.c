#include "_vm_params.h"

int 				_vm_params_flag_cycles(t_vm_params *self, char *param)
{
	long long num;
	num = ft_atol(param);
	if (!(ft_arg_is_num(param)))
		raise(__FILE__, __LINE__, ENOARGVAL);
	self->nb_cycles = num;
//	printf("s_cycles %d\n", self->nb_cycles);
	return (FLAG_NUM_CODE);

}