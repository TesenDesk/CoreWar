/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_map_hashcode.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 15:28:25 by ftothmur          #+#    #+#             */
/*   Updated: 2020/02/28 15:45:41 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long		ft_hash_map_hashcode(unsigned char *str)
{
	unsigned long long	hash;
	int					c;

	c = 0;
	hash = HASH_CONST;
	while ((c = (int)*str++))
		hash = ((hash << 5) + hash) ^ c;
	return (hash);
}
