/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _code.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:10:32 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 18:54:01 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CODE_H
# define _CODE_H

# include "error.h"
# include "code.h"

typedef struct			s_code
{
	void			*data;
	int				size;
}						t_code;


#endif