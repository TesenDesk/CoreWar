#include "_file.h"

# define COREWAR_EXEC_MAGIC			15369203 // 0xea83f3;
# define COREWAR_EXEC_MAGIC_LENGTH	4
# define PROG_NAME_LENGTH			128
# define NULL_LENGTH				4
# define CHAMP_MAX_SIZE				682
# define CHAMP_SIZE_LENGTH			4
# define COMMENT_LENGTH				2048

ssize_t		*file_total(t_file *self)
{
	return (self->total);
}