/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_corwar.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 22:37:19 by yurezz            #+#    #+#             */
/*   Updated: 2020/08/23 14:13:59 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRVT_CORWAR_H
# define PRVT_CORWAR_H

# include "libft.h"
# include "errors.h"
# include "corwar.h"
# include "op.h"
# include "vm.h"

# define DEFAULT_MODE 0
# define VISUAL_MODE 1

typedef void				(*t_vm_play_fptr)(t_vm *);

#endif
