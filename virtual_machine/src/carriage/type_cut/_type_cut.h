/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _type_cut.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 23:14:20 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/09 23:29:43 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TYPE_CUT_H

# define _TYPE_CUT_H

# include "libft.h"
# include "error.h"
# include "op.h"
# include "carriage.h"
# include "type_cut.h"

# define TYPES_BY_LEN_NB	4

typedef void	(*t_type_cutter)(long int *nb);

void			_type_cut_char(long int *registers);
void			_type_cut_short(long int *registers);
void			_type_cut_int(long int *registers);
void			_type_cut_long_int(long int *registers);

#endif
