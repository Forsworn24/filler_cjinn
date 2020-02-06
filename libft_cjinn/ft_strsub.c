/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjinn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:33:04 by cjinn             #+#    #+#             */
/*   Updated: 2019/04/18 19:42:40 by cjinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	i = 0;
	if (!s || start + len > ft_strlen(s))
		return (NULL);
	if ((res = ft_strnew(len)))
	{
		while (len)
		{
			res[i++] = s[start++];
			len--;
		}
		res[i] = '\0';
	}
	return (res);
}
