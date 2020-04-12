/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:10:32 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/12 13:31:16 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGUMENTS_H
# define ARGUMENTS_H

# include "libft.h"
# include "error.h"

enum			e_arguments_singleton
{
	ARGUMENTS_INSTANTIATE,
	ARGUMENTS_DESTRUCT,
};

typedef struct s_arguments		t_arguments;

t_arguments			*arguments_singleton(int instantiation_status);

#endif
