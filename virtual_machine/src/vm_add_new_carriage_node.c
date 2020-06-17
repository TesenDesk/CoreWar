#include "_vm.h"

//don`t checked
void        vm_add_new_carriage_node(t_list *new_node)
{
    t_vm    *vm;

    vm = vm_singleton(VM_INSTANTIATE, 0, NULL);
    ft_lstadd(&(vm->carriage_head), new_node);
//    t_list  *head;
//
//    head = vm->carriage_head;
//    ft_lstadd(&(vm->carriage_head), new_node);
//    vm->carriage_head = head;
}