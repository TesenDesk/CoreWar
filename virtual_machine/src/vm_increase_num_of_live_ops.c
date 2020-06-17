#include "_vm.h"
 void       vm_increase_num_of_live_ops()
 {
    t_vm    *vm;
    vm = vm_singleton(VM_INSTANTIATE, 0, NULL);
    vm->num_of_live_ops += 1;
 }