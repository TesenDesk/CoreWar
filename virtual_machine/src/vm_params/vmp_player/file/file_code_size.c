#include "_file.h"
# define COREWAR_EXEC_MAGIC			15369203 // 0xea83f3;
# define COREWAR_EXEC_MAGIC_LENGTH	4
# define PROG_NAME_LENGTH			128
# define NULL_LENGTH				4
# define CHAMP_MAX_SIZE				682
# define CHAMP_SIZE_LENGTH			4
# define COMMENT_LENGTH				2048

size_t      file_code_size(tt_file * self)
{
    char		*code_size_in_data;
    unsigned int		code_size;

    code_size_in_data = (char*)(self->data)
        + COREWAR_EXEC_MAGIC_LENGTH
        + PROG_NAME_LENGTH
        + NULL_LENGTH;
    code_size = (*(int*)code_size_in_data);
    code_size = (int)((code_size << 24)
        | ((code_size & 0xff00) << 8)
        | ((code_size & 0xff0000) >> 8)
        | (code_size>> 24));
    return (code_size);
}