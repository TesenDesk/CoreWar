#include "_arena.h"

//don`t checked
void        arena_write_four_bytes_to_data(t_arena *self, int pos, int new_data)
{
    char        *data;
    int         i;
    char        new_char_value;

    data = self->data;
    if (pos < 0)
        pos = MEM_SIZE + pos % MEM_SIZE;
    i = 0;
    while (i < 4)
    {
        new_char_value = (char)(new_data >> (EIGHT_BITS * (3 - i)));
        data[(pos + i) % MEM_SIZE] = new_char_value;
        i++;
    }
}