#include "prvt_operation.h"

int                 prvt_op_num_of_args(int op_code)
{
	static int      num_of_args[] =
			{0, 2, 2, 3, 3, 3, 3, 3, 1, 3, 3, 1, 2, 3, 1, 1};
	return (num_of_args[op_code]);
}