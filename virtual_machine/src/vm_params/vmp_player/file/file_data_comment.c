#include "_file.h"
# define COREWAR_EXEC_MAGIC			15369203 // 0xea83f3;
# define COREWAR_EXEC_MAGIC_LENGTH	4
# define PROG_NAME_LENGTH			128
# define NULL_LENGTH				4
# define CHAMP_MAX_SIZE				682
# define CHAMP_SIZE_LENGTH			4
# define COMMENT_LENGTH				2048

char		*file_data_comment(t_file *self)
{
	char		*comment_in_data;
	char		*comment;

	comment_in_data = (char*)(self->data)
		+ COREWAR_EXEC_MAGIC_LENGTH
		+ PROG_NAME_LENGTH
		+ NULL_LENGTH
		+ CHAMP_SIZE_LENGTH;
	if (!(comment = ft_strdup(comment_in_data)))
		raise(__FILE__, __LINE__, ENOMEMORY);
	return (comment);
}