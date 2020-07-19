/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codegen_prototype.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 19:55:55 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/19 20:12:38 by cmissy           ###   ########.fr       */
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

#endif
