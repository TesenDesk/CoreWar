/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_expr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:25:58 by cmissy            #+#    #+#             */
/*   Updated: 2020/08/22 12:57:29 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRVT_EXPR_H
# define PRVT_EXPR_H

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
