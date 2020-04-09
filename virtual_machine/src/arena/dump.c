#include "libft.h"
// #include "_errors.h"
#include "_arena.h"
# define DUMP_LINE_SIZE			32 //bytes
# define MEM_SIZE				(4 * 1024)
# define SPACE					' '
# define EOL					'\n'

void	print_dump(void *arena)
{
	int		index;
	int		i;
	int		buffer_len;
	char	*buffer;
	char	*data;

	// buffer_len = sizeof(char) * (DUMP_LINE_SIZE * 3);
	buffer_len = DUMP_LINE_SIZE * 3;
	buffer = ft_memalloc(buffer_len);
	// data = (char)arena.data;
	// data = (char)arena.data + MEM_SIZE - 1;
	// data = (char*)arena + MEM_SIZE - 1;
	data = (char*)arena;
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
		else
			buffer[i++] = SPACE;
	}
	// (void)vm_singleton(VM_DESTRUCT, 0, NULL);
}

int		main()
{
	void	*arena = ft_memalloc(MEM_SIZE);

	print_dump(arena);
}