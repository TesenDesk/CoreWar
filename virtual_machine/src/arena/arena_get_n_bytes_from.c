#include "_arena.h"

#define EIGHT_BITS      8

int         arena_get_n_bytes_from(t_arena *self, int pos, int num_of_bytes)
{
    char    *from;
    int     bytes;

    from = (char*)(self->data) + pos;
    bytes = 0;
    while (num_of_bytes)
    {
        bytes = bytes << EIGHT_BITS;
        bytes |= *from;
        from++;
        num_of_bytes--;
    }
    return bytes;
}