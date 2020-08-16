/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_asm.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 14:45:41 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/16 14:49:02 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_ASM_H
# define MAIN_ASM_H

# include "libft.h"

typedef struct s_hash_map	t_hash_map;
typedef struct s_analyser	t_analyser;

typedef struct	s_main_asm
{
	t_hash_map		*map;
	t_vector		*text;
	t_analyser		*analyser;
	t_vector		vtr;
	char			*buf;
	int				count;
}				t_main_asm;

#endif