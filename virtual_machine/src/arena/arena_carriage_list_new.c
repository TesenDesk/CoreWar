#include "_arena.h"
#include "carriage.h"
#include "_carriage.h"

t_list          *arena_carriage_list_new(t_arena *self)
{
    t_list      *head;
    t_list      *new_node;
    t_carriage  *curr_carriage;
    int         step;
    int         i;

    i = 0;
    step = MEM_SIZE / self->nb_players;
    head = NULL;
    new_node = NULL;
    curr_carriage = NULL;
    while (i < self->nb_players)
    {
        curr_carriage = carriage_new(i + 1, self, i * step);
        if ((new_node = ft_lstnew((void *) curr_carriage, sizeof(t_carriage))) == NULL)
            raise(__FILE__, __LINE__, ENOMEMORY);
        ft_lstadd(&head, new_node);
        i += 1;
    }
    return head;
}