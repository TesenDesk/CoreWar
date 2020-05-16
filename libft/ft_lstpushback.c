
#include "libft.h"

void	ft_lstpushback(t_list **head, t_list *new)
{
    t_list  *tmp;
    if (head && new)
    {
        if (*head == NULL)
        {
            *head = new;
        }
        else
        {
            tmp = *head;
            while (tmp->next != NULL)
                tmp = tmp->next;
            tmp->next = new;
        }
    }
    return ;
}
