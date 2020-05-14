/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vmp_player_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita_toropov <nikita_toropov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:28:46 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/25 18:41:00 by nikita_toro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm_params/vmp_player/file/_file.h>
#include "_vmp_player.h"



# define MAX_PLAYERS			4
# define DUMP_LINE_SIZE			32 //bytes
# define MEM_SIZE				(MAX_PLAYERS * 1024)
# define SPACE					' '
# define EOL					'\n'
#include <fcntl.h>

void			file_print_dump(tt_file *self)
{
	size_t		index;
	size_t		i;
	size_t		buffer_len;
	char    	*buffer;
	char	    *data;
	buffer_len = DUMP_LINE_SIZE * 3;
	buffer = ft_memalloc(buffer_len);
	data = (char*)self->data;
	index = 0;
	i = 0;
	int fd = open("./our_bee_gees.cor", O_RDWR);
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
			write(fd, buffer, buffer_len);
		}
		else
			buffer[i++] = SPACE;
	}
	// (void)vm_singleton(VM_DESTRUCT, 0, NULL);
}


void			file_print_dump2(char *filename)
{
	size_t		index;
	size_t		i;
	size_t		buffer_len;
//	char    	*buffer;
	char	    *data;
	buffer_len = DUMP_LINE_SIZE * 3;
	char buffer[buffer_len];
	for (int i = 0; i < buffer_len; ++i)
		*(buffer + i) = 0;
	int fd = open(filename, O_RDONLY);
//	data = filename;
	index = 0;
	i = 0;
	int nn = 0;
	char *bb = ft_memalloc(1000);
	while ((nn = read(fd, bb, 1)))
	{
		buffer[i] = '0';
		if (*bb < 16)
			ft_uintmaxtostr(&buffer[i + 1], *bb, 16, 0);
		else
			ft_uintmaxtostr(&buffer[i], *bb, 16, 0);
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
}


t_vmp_player		*vmp_player_new(int player_name, char *file_name)
{
	t_vmp_player	*self;

//	if ((self = (t_vmp_player *)ft_memalloc(10000)) == NULL)
	if ((self = (t_vmp_player *)ft_memalloc(sizeof(t_vmp_player))) == NULL)
		raise(__FILE__, __LINE__, ENOMEMORY);
	self->player_name = player_name;
//	printf("%d, %d\n\n", player_name, self->player_name);
	if (file_name != PFILE_MOCK)
		self->file = file_new(file_name);
	return (self);
}
