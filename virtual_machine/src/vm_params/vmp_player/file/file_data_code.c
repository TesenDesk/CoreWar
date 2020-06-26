#include "_file.h"
# define COREWAR_EXEC_MAGIC			15369203 // 0xea83f3;
# define COREWAR_EXEC_MAGIC_LENGTH	4
# define PROG_NAME_LENGTH			128
# define NULL_LENGTH				4
# define CHAMP_MAX_SIZE				682
# define CHAMP_SIZE_LENGTH			4
# define COMMENT_LENGTH				2048

void		*file_data_code(tt_file *self)
{
	char		*code_in_data;
	char		*code;
	char		*code_size_in_data;
//	size_t		code_size;
	unsigned int		code_size;

	code_in_data = (char*)(self->data)
		+ COREWAR_EXEC_MAGIC_LENGTH
		+ PROG_NAME_LENGTH
		+ NULL_LENGTH
		+ CHAMP_SIZE_LENGTH
		+ COMMENT_LENGTH
		+ NULL_LENGTH;
	code_size_in_data = (char*)(self->data)
		+ COREWAR_EXEC_MAGIC_LENGTH
		+ PROG_NAME_LENGTH
		+ NULL_LENGTH;
	code_size = *(unsigned int*)code_size_in_data;
	code_size = (int)((code_size << 24)
		| ((code_size & 0xff00) << 8)
		| ((code_size & 0xff0000) >> 8)
		| (code_size>> 24));
	if (!(code = ft_memalloc(code_size)))
		raise(__FILE__, __LINE__, ENOMEMORY);
    ft_memcpy(code, code_in_data, code_size);
	return (code);
}

//void		*file_data_code(tt_file *self)
//{
//	char		*code_in_data;
//	void		*code;
//
//	code_in_data = (char*)(self->data)
//		+ COREWAR_EXEC_MAGIC_LENGTH
//		+ PROG_NAME_LENGTH
//		+ NULL_LENGTH
//		+ CHAMP_SIZE_LENGTH
//		+ COMMENT_LENGTH
//		+ NULL_LENGTH;
//	if (!(code = (void*)ft_strdup(code_in_data)))
//		raise(__FILE__, __LINE__, ENOMEMORY);
//	return (code);
//}