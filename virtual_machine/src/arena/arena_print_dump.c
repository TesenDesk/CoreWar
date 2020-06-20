#include "_arena.h"

# define DUMP_LINE_SIZE			32 //bytes
# define MAX_PLAYERS			4
//# define MEM_SIZE				(MAX_PLAYERS * 1024)
# define SPACE					' '
# define EOL					'\n'
# define PREFIX_SIZE			9

static void            set_index_in_buffer(char *buffer, int index) {
    if (index & 0xf000)
        ft_uintmaxtostr(&buffer[2], index, 16, 0);
    else if (index & 0xf00)
        ft_uintmaxtostr(&buffer[3], index, 16, 0);
    else if (index & 0xf0)
        ft_uintmaxtostr(&buffer[4], index, 16, 0);
    else if (index & 0xf)
        ft_uintmaxtostr(&buffer[5], index, 16, 0);
    buffer[6] = ' '; // GENIUS SO GENIUS! BEST WAY! DONT'TOUCH! BRILLIANT WAY! MORE SHIT CODE! MORE AND MORE
}


void			arena_print_dump(t_arena *self)
{
    size_t		index;
    size_t		i;
    size_t		buffer_len;
    char    	*buffer;
    char	    *data;


    buffer_len = DUMP_LINE_SIZE * 3 + PREFIX_SIZE;
    buffer = ft_memalloc(buffer_len);
    data = (char*)self->data;
    ft_memcpy(buffer, "0x0000 : ", 9);


    index = 0;
    i = PREFIX_SIZE;
    while (index < MEM_SIZE)
    {
        buffer[i] = '0';
        if (data[index] & 0xf0)
            ft_uintmaxtostr(&buffer[i], ((unsigned int)data[index] & 0xff), 16, 0);
        else
            ft_uintmaxtostr(&buffer[i + 1], (unsigned int)data[index], 16, 0);
        i += 2;
        index++;

        if (!(index % DUMP_LINE_SIZE))
        {
            buffer[i] = EOL;
            i = PREFIX_SIZE;
            write(1, buffer, buffer_len);
            set_index_in_buffer(buffer, index);
        }
        else
            buffer[i++] = SPACE;
//        printf("%x ", ((unsigned int)data[index++] & 0xff));
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
//    while (index < MEM_SIZE)
//    {
//        buffer[i] = '0';
//        if (data[index] & 0xf0)
//            ft_uintmaxtostr(&buffer[i], ((unsigned int)data[index] & 0xff), 16, 0);
//        else
//            ft_uintmaxtostr(&buffer[i + 1], (unsigned int)data[index], 16, 0);
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
////        printf("%x ", ((unsigned int)data[index++] & 0xff));
//    }
//    // (void)vm_singleton(VM_DESTRUCT, 0, NULL);
//}