/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjinn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:01:41 by cjinn             #+#    #+#             */
/*   Updated: 2019/04/18 19:13:35 by cjinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*h;
	size_t	n_len;
	size_t	i;
	size_t	j;
	size_t	k;

	k = 0;
	h = (char *)haystack;
	while (needle[k] != '\0')
		k++;
	if (!(n_len = k))
		return (h);
	i = 0;
	while (h[i])
	{
		j = 0;
		while (needle[j] && needle[j] == h[j + i])
			j++;
		if (j == n_len)
			return (&h[i]);
		i++;
	}
	return (NULL);
}
