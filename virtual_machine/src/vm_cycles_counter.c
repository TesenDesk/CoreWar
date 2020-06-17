#include "_vm.h"

int         vm_cycles_counter()
{
    t_vm    *vm;

    vm = vm_singleton(VM_INSTANTIATE, 0, NULL);
    return (vm->cycles_counter);
}