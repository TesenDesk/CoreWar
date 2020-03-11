/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_uintmax.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 22:09:08 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/23 04:05:36 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		move_through_radix_symbols(char **input_str, int radix)
{
	char		*str;

	str = *input_str;
	if (radix == 2 || radix == 8 || radix == 16)
	{
		if (*str == '0')
		{
			++str;
			if ((radix == 8 && ft_tolower(*str) == 'b') ||
				(radix == 16 && ft_tolower(*str) == 'x'))
				++str;
			*input_str = str;
		}
	}
	return ;
}

static void		set_radix_if_absent(char **input_str, int *radix)
{
	char		*str;

	str = *input_str;
	if (!*radix)
	{
		if (*str == '0')
		{
			++str;
			if (*str == 'b' || *str == 'B' || *str == 'x' || *str == 'X')
			{
				*radix = (*str == 'b' || *str == 'B') ? 2 : 16;
				++str;
			}
			else
				*radix = 8;
		}
		else
			*radix = 10;
		*input_str = str;
	}
	else
		move_through_radix_symbols(input_str, *radix);
	return ;
}

static int		check_sign(char **input_str, int radix, int *sign)
{
	char		*str;

	str = *input_str;
	*sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (radix != 10)
			return (FAILURE);
		else
			*sign = *str++ == '-' ? -1 : 1;
	}
	*input_str = str;
	return (SUCCESS);
}

static void		final_initialization(uintmax_t **nbr, int radix,
					uintmax_t *cut_off, uintmax_t *cut_lim)
{
	**nbr = 0;
	*cut_off = UINTMAX_MAX / radix;
	*cut_lim = UINTMAX_MAX % radix;
	return ;
}

int				ft_str_to_uintmax(char *str, char **endptr,
					int radix, uintmax_t *nbr)
{
	int				sign;
	uintmax_t		cut_off;
	uintmax_t		cut_lim;
	uintmax_t		appendix;

	if (!str || !endptr || radix < 0 || radix == 1 || radix > 36 || !nbr)
		return (FAILURE);
	str = (char *)ft_spskip(str);
	set_radix_if_absent(&str, &radix);
	if (check_sign(&str, radix, &sign))
		return (FAILURE);
	while (*str == '0')
		++str;
	final_initialization(&nbr, radix, &cut_off, &cut_lim);
	while (*str && ft_strnchr(RADIX_CYPHERS_STR, ft_tolower(*str), radix - 1))
	{
		appendix = ft_tolower(*str) - (ft_isdigit(*str) ? '0' : ('a' - 10));
		if (*nbr > cut_off || (*nbr == cut_off && appendix > cut_lim))
			return (FAILURE);
		*nbr = (*nbr * radix) + appendix;
		++str;
	}
	*endptr = str;
	return (SUCCESS);
}
