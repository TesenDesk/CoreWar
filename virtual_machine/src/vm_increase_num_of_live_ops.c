#include "_vm.h"
 void       vm_increase_num_of_live_ops(t_vm *self)
 {
    self->num_of_live_ops += 1;
 }