/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codegen.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 21:20:17 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/19 20:21:42 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_CODEGEN_H
# define CORE_CODEGEN_H

# include "op.h"
# include "libft.h"
# include "ft_printf.h"
# include "expr.h"

typedef struct s_codegen	t_codegen;

typedef struct				s_label_data
{
	char					*name;
	unsigned int			add;
	unsigned int			instruction_begining;
	int						size;
	int						param_type;
}							t_label_data;

void						generate_code(t_hash_map *map, t_vector *text,
							char *filename);


typedef struct					s_header
{
	unsigned int				magic;
	char						prog_name[PROG_NAME_LENGTH + 1];
	unsigned int				prog_size;
	char						comment[COMMENT_LENGTH + 1];
}								t_header;

#endif
