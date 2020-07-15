/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:55:10 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:55:11 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 	In the string, dst searches for the occurrence of the string src in the
** first size characters.
**	Returns:
** If src is empty, then the pointer to dst.
** If the required substring is not found, then a pointer to NULL.
** Otherwise, a pointer to a substring.
**
**	First, the conditions for missing arguments are processed by reference. If
** they are not there, and also if the string dst, where the search will be
** ed, is empty, or the number of characters for the search, size is 0,
** and also if the string src, whose entry in dst is searched, does not fit
** there, in all these Cases will return a null pointer. (By end symbol from
** dst). The same result will be if there is no substring in dst equal to src
** within the first size characters.
**	The function in the loop first searches for the nearest occurrence of the
** first src character in the given dst part (the crt character, the current
** one). Every time when we find it, it checks whether src enters dst from this
** viewing point.
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*h;
	char	*n;
	size_t	l;

	if (!*needle)
		return ((char*)haystack);
	while (*haystack != '\0' && len > 0)
	{
		h = (char*)haystack;
		n = (char*)needle;
		l = len;
		while (*n != '\0' && *n == *h && l > 0)
		{
			n++;
			h++;
			l--;
		}
		if (l == 0)
			return ((char*)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
