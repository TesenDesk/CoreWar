#include "_vm.h"

int			vm_verbosity_lvl()
{
	t_vm	*vm;

	vm = vm_singleton(VM_INSTANTIATE, 0, NULL);
	return (vm->verbosity_lvl);
}