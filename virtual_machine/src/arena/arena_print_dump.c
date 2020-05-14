#include "_arena.h"

# define DUMP_LINE_SIZE			32 //bytes
# define MAX_PLAYERS			4
# define MEM_SIZE				(MAX_PLAYERS * 1024)
# define SPACE					' '
# define EOL					'\n'

void			arena_print_dump(t_arena *self)
{
    size_t		index;
    size_t		i;
    size_t		buffer_len;
    char    	*buffer;
    char	    *data;


    buffer_len = DUMP_LINE_SIZE * 5 / 2; // every byte want 2 chars 00 and 0.5 spaces
    buffer = ft_memalloc(buffer_len);
    data = (char*)self->data;
    index = 0;
    i = 0;
    while (index < MEM_SIZE)
    {
        buffer[i] = '0';
        if (data[index] < 16)
            ft_uintmaxtostr(&buffer[i + 1], data[index], 16, 0);
        else
            ft_uintmaxtostr(&buffer[i], data[index], 16, 0);
        i += 2;
        index++;
        if (!(index % DUMP_LINE_SIZE))
        {
            buffer[i] = EOL;
            i = 0;
            write(1, buffer, buffer_len);
        }
        else if (!(index % 2))
            buffer[i++] = SPACE;
    }
    // (void)vm_singleton(VM_DESTRUCT, 0, NULL);
}

//void			arena_print_dump(t_arena *self)
//{
//    size_t		index;
//    size_t		i;
//    size_t		buffer_len;
//    char    	*buffer;
//    char	    *data;
//
//
//    buffer_len = DUMP_LINE_SIZE * 3;
//    buffer = ft_memalloc(buffer_len);
//    data = (char*)self->data;
//    index = 0;
//    i = 0;
//    write(1, "\n\n", 2);
//    while (index < MEM_SIZE)
//    {
//        buffer[i] = '0';
//        if (data[index] < 16)
//            ft_uintmaxtostr(&buffer[i + 1], data[index], 16, 0);
//        else
//            ft_uintmaxtostr(&buffer[i], data[index], 16, 0);
//        i += 2;
//        index++;
//        if (!(index % DUMP_LINE_SIZE))
//        {
//            buffer[i] = EOL;
//            i = 0;
//            write(1, buffer, buffer_len);
//        }
//        else
//            buffer[i++] = SPACE;
//    }
//    write(1, "\n\n", 2);
//    // (void)vm_singleton(VM_DESTRUCT, 0, NULL);
//}