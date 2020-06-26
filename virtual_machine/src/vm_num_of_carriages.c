#include "_vm.h"

int       vm_num_of_carriages_and_increase()
{
    t_vm    *vm;

    vm = vm_singleton(VM_INSTANTIATE, 0, NULL);
    vm->num_of_carriages += 1;
    return (vm->num_of_carriages);
}