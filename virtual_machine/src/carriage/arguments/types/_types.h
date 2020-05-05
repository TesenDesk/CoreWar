/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _types.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 19:37:39 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/14 22:20:38 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef _DOES_MATCH_H
# define _DOES_MATCH_H

# include "operation.h"
# include "types.h"

typedef int			(*t_types)(t_arguments *arguments);

int					_types_not_nil_not_nil_reg(int self);
int					_types_not_nil_dir_or_reg_reg(int self);

#endif
