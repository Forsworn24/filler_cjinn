/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjinn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 18:07:56 by cjinn             #+#    #+#             */
/*   Updated: 2019/04/18 19:11:43 by cjinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*str;
	char			*strn;
	unsigned int	counter;

	str = (char *)s;
	if (str && f)
	{
		counter = 0;
		if (!(strn = ft_memalloc(ft_strlen(str) + 1)))
			return (NULL);
		while (str[counter])
		{
			strn[counter] = (*f)(str[counter]);
			counter++;
		}
		strn[counter] = '\0';
		return (strn);
	}
	return (NULL);
}
