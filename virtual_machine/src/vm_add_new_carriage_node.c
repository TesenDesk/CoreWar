#include "_vm.h"

void		vm_add_new_carriage_node(t_list *new_node)
{
	t_vm	*vm;

	vm = vm_singleton(VM_INSTANTIATE, 0, NULL);
	ft_lstadd(&(vm->carriage_head), new_node);
}