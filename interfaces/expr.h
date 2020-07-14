/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 21:14:42 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/14 21:14:43 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPR_H
# define EXPR_H

# include "token.h"
# include "expr_defines.h"

typedef struct s_expr		t_expr;
typedef struct s_arg		t_arg;

typedef enum		e_arg_number
{
	UNDEF_ARG = -1,
	OP_NAME,
	FIRST_ARG,
	SECOND_ARG,
	THIRD_ARG,
	LABEL_ARG,
}					t_arg_number;

t_expr				*expr_ctor(void);
void				expr_dtor(t_expr **expr);
int					expr_set_arg(t_expr *expr, t_token *token,
						int args_number, int arg_type);
void				*expr_get_arg_value(t_expr *expr, int index);

#endif
