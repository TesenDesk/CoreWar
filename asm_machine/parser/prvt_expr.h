/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_private.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:25:58 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/19 18:34:48 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPR_PRIVATE_H
# define EXPR_PRIVATE_H


# include "expr.h"

typedef struct		s_arg
{
	int				type;
	void			*value;
}					t_arg;

typedef struct		s_expr
{
	int				type;
	int				arg_size;
	int				size;
	void			*name;
	t_arg			args[7];
}					t_expr;

#endif
