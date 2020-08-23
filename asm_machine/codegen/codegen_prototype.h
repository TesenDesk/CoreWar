/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codegen_prototype.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 19:55:55 by cmissy            #+#    #+#             */
/*   Updated: 2020/08/23 14:57:29 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEGEN_PROTOTYPE_H
# define CODEGEN_PROTOTYPE_H

# include "codegen.h"

typedef union		u_code_addr
{
	void			*content;
	unsigned int	addr;
}					t_code_addr;

int					champ_exec_constructor(t_codegen *data);
void				label_dtor(void **data);
void				codegen_dtor(t_codegen *code);
t_codegen			*codegen_ctor(t_hash_map *labels_free, t_header *header);

#endif
