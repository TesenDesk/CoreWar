/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codegen_header_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:46:22 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/23 13:46:54 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_codegen.h"

void			init_header(t_header *header, t_vector *text)
{
	char		*name;
	char		*comment;

	name = token_get_value(expr_get_arg_value(text->items[0], 0));
	comment = token_get_value(expr_get_arg_value(text->items[1], 0));
	ft_bzero(header->comment, COMMENT_LENGTH + 1);
	ft_bzero(header->prog_name, PROG_NAME_LENGTH + 1);
	ft_memcpy(header->prog_name, name, ft_strlen(name));
	ft_memcpy(header->comment, comment, ft_strlen(comment));
	header->magic = COREWAR_EXEC_MAGIC;
}
