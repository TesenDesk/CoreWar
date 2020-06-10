#include "_operation.h"

void				*operation_dispatched(int state)
{
    static t_operation	operations[NUMBER_OF_OPERATIONS] =
            {
//                    _operation_mock,
                    _operation_live,
//                    _operation_ld,
//                    _operation_st,
//                    _operation_add,
//                    _operation_sub,
//                    _operation_and,
//                    _operation_or,
//                    _operation_xor,
//                    _operation_zjmp,
//                    _operation_ldi,
//                    _operation_sti,
//                    _operation_fork,
//                    _operation_lld,
//                    _operation_lldi,
//                    _operation_lfork,
//                    _operation_aff,
            };

//    return (operations[state]);
}