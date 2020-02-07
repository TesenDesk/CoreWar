/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_w.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 21:35:16 by cmissy            #+#    #+#             */
/*   Updated: 2019/04/30 21:35:35 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_num_w(char const *str, char c)
{
	int			n;

	n = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str && *str != c)
			n++;
		while (*str && *str != c)
			str++;
	}
	return (n);
}
