/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintmaxtostr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:52:02 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/07 16:19:56 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**						   ft_imaxtostr().
**						____________________
**	PURPOSE:
**	The function translates representations of numbers from memory into a given
** number system (from 2 to 36). By default, it accepts unsigned integers,
** however, by controlling the fourth parameter, you can specify the operation
** with a sign.
**	ARGUMENTS:
**		str		: buffer for writing the result string. If empty, then skipping
**				computations, a pointer to the string is returned.
**		nbr		: the number to be converted.
**		radix	: the base of the number system. If equal to 0, then equal to
**				10. If equal to 1 or greater than 36, only zero byte is written
**				to the string.
**		issign: = 1 if there is a sign, otherwise! = 0.
**	OUTPUT:
**				: Pointer to the end of line character.
*/

static int		prepare(char *str, uintmax_t *nbr, t_ui *radix, int *issign)
{
	int			isnegative;

	isnegative = !TRUE;
	if (!str || *radix == 1 || *radix > 36)
	{
		if (str)
			*str = '\0';
		return (FAIL);
	}
	if (!*radix)
		*radix = 10;
	if (*issign && *nbr > (uintmax_t)INTMAX_MAX)
		isnegative = !!TRUE;
	if (isnegative)
		*nbr = (((*nbr) << REMOVE_SIGN) >> REMOVE_SIGN);
	else
		*issign = !TRUE;
	return (SUCCESS);
}

char			*ft_uintmaxtostr(char *str, uintmax_t nbr, t_ui radix,
		int issign)
{
	t_uimaxdiv	div_r;
	char		*radix_cyphers;
	char		*zero;

	if (prepare(str, &nbr, &radix, &issign))
		return (str);
	zero = str;
	radix_cyphers = "0123456789abcdefghijklmnopqrstuvwxyz";
	div_r = ft_uimaxdiv(nbr, radix);
	while (div_r.quot)
	{
		*zero++ = *(radix_cyphers + div_r.rem);
		div_r = ft_uimaxdiv(div_r.quot, radix);
	}
	*zero++ = *(radix_cyphers + div_r.rem);
	if (issign)
		*zero++ = '-';
	*zero = '\0';
	ft_strrev(str);
	return (zero);
}
