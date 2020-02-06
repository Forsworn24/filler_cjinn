/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjinn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:48:24 by cjinn             #+#    #+#             */
/*   Updated: 2019/04/18 19:13:08 by cjinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	l;
	size_t	j;
	char	*h;

	h = (char *)haystack;
	if (!(l = ft_strlen(needle)))
		return (h);
	if (ft_strlen(haystack) < l || len < l)
		return (NULL);
	i = 0;
	while (h[i] && i <= len - l)
	{
		j = 0;
		while (needle[j] && needle[j] == h[i + j])
			j++;
		if (j == l)
			return (&h[i]);
		i++;
	}
	return (NULL);
}
