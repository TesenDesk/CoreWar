/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codegen.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 21:20:17 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/14 21:20:23 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_CODEGEN_H
# define CORE_CODEGEN_H

# include "op.h"
# include "libft.h"
# include "expr.h"
# include "expr_defines.h"
# include "../parser/expr_private.h"

typedef struct s_codegen	t_codegen;

void			generate_code(t_hash_map *map, t_vector *text, char *filename);
#endif
