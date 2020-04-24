#include "_file.h"
# define COREWAR_EXEC_MAGIC			15369203 // 0xea83f3;
# define COREWAR_EXEC_MAGIC_LENGTH	4
# define PROG_NAME_LENGTH			128
# define NULL_LENGTH				4
# define CHAMP_MAX_SIZE				682
# define CHAMP_SIZE_LENGTH			4
# define COMMENT_LENGTH				2048

static int		file_check_data_size(t_file *self)
{
	ssize_t			min_size;
	ssize_t			code_size;
	ssize_t			data_file_size;
	void			*code_size_in_data;

	min_size = COREWAR_EXEC_MAGIC_LENGTH
		+ PROG_NAME_LENGTH
		+ NULL_LENGTH
		+ CHAMP_SIZE_LENGTH
		+ COMMENT_LENGTH
		+ NULL_LENGTH;
	code_size = (ssize_t)(*(int*)
		((char*)(self->data) // check code construction
		+ COREWAR_EXEC_MAGIC_LENGTH
		+ PROG_NAME_LENGTH
		+ NULL_LENGTH));
	data_file_size = min_size + code_size;
	if (self->total < min_size
	|| code_size > CHAMP_MAX_SIZE
	|| data_file_size != self->total)
		return (1);
	return (0);
}

static int		file_data_check_nulls(t_file *self)
{
	int			first_null;
	int			second_null;

	first_null = *((int*)((char*)(self->data)
		+ COREWAR_EXEC_MAGIC_LENGTH
		+ PROG_NAME_LENGTH));
	second_null = *((int*)((char*)(self->data)
		+ COREWAR_EXEC_MAGIC_LENGTH
		+ PROG_NAME_LENGTH
		+ NULL_LENGTH
		+ CHAMP_SIZE_LENGTH
		+ COMMENT_LENGTH));
	if (first_null || second_null)
		return (1);
	return (0);
}

static int		file_data_magic_header_check(t_file *self)
{
	int			data_magic_header;

	data_magic_header = *((int*)(self->data));
	if (data_magic_header != COREWAR_EXEC_MAGIC)
		return (1);
	return (0)
}

int				file_data_precondition_check(t_file *self)
{
	int		result
	if (file_check_data_size(t_file *self))
	{
		// error way
	}
	else if (file_data_check_nulls(t_file *self))
	{

	}
	else if (file_data_magic_header_check(t_file *self))
	{

	}
}