#include "_operation.h"

int         _operation_arguments_conversion_to_int(int raw, int num_of_bytes)
{
    if (num_of_bytes == 1 && raw & 0x80)
    else if (num_of_bytes == 2 && && raw & 0x8000)
    else if (num_of_bytes == 3 && && raw & 0x800000)
    else if (num_of_bytes == 4 && && raw & 0x80000000)

}