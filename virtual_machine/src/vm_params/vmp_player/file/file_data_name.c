#include "_file.h"
# define COREWAR_EXEC_MAGIC_LENGTH	4

char		*file_data_name(tt_file *self)
{
	char		*name_in_data;
	char		*name;

	name_in_data = (char*)(self->data)
		+ COREWAR_EXEC_MAGIC_LENGTH;
	if (!(name = ft_strdup(name_in_data)))
		raise(__FILE__, __LINE__, ENOMEMORY);
	return (name);
}