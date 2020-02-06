/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjinn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:41:12 by cjinn             #+#    #+#             */
/*   Updated: 2019/04/18 19:41:04 by cjinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *res;
	char *start;

	if (!s1 && !s2)
		return (NULL);
	res = ft_strnew((s1 ? ft_strlen(s1) : 0) + (s2 ? ft_strlen(s2) : 0));
	if ((start = res))
	{
		if (s1)
			while (*s1)
				*res++ = *s1++;
		if (s2)
			while (*s2)
				*res++ = *s2++;
		*res = '\0';
	}
	return (start);
}
