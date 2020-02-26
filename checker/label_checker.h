/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_checker.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:18:04 by ftothmur          #+#    #+#             */
/*   Updated: 2020/02/26 19:51:22 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LABEL_CHECKER_H
# define LABEL_CHECKER_H

#include "libft.h"

int				label_checker_put_to_map_label_word(
				t_hash_map **map_of_label_words, char const **text);
int				label_checker_put_to_map_label_ptr(
				t_hash_map **map_of_label_ptrs, char const **text);

#endif