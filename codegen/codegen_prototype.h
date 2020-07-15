/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codegen_prototype.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 19:55:55 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/15 19:33:37 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEGEN_PROTOTYPE_H
# define CODEGEN_PROTOTYPE_H
# include "codegen.h"

typedef struct		s_label_data
{
	char			*name;
	unsigned int	add;
	unsigned int	instruction_begining;
	int				size;
	int				param_type;
}					t_label_data;

typedef union		u_code_addr
{
	void			*content;
	unsigned int	addr;
}					t_code_addr;

#endif
