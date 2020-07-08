#include "_vm.h"

void		vm_carriage_list_destruct(t_list **carriage_list)
{
	ft_lstdel(carriage_list, carriage_destroy);
}