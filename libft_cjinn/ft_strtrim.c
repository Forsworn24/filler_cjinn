/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjinn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:47:51 by cjinn             #+#    #+#             */
/*   Updated: 2019/04/18 20:00:52 by cjinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlast(char *str, const char *charset)
{
	unsigned int	i;
	int				index;
	unsigned int	count;
	unsigned int	tmp;

	count = 0;
	i = (unsigned int)ft_strlen(str) - 1;
	while (str[i])
	{
		index = 0;
		tmp = count;
		while (charset[index])
			if (charset[index++] == str[i])
				++count;
		if (count == tmp)
			return (count);
		--i;
	}
	return (count);
}

unsigned int	ft_strfirst(char *str, const char *charset)
{
	char			*ptr;
	int				index;
	unsigned int	count;
	unsigned int	tmp;

	ptr = str;
	count = 0;
	while (*ptr)
	{
		index = 0;
		tmp = count;
		while (charset[index])
			if (charset[index++] == *ptr)
				++count;
		if (count == tmp)
			return (count);
		++ptr;
	}
	return (count);
}

char			*ft_strtrim(char const *s)
{
	char			*res;
	unsigned int	start;
	unsigned int	size;
	unsigned int	spaces_count;

	if (!s)
		return (NULL);
	size = (unsigned int)ft_strlen((char *)s);
	spaces_count = ft_strfirst((char *)s, " \n\t");
	start = spaces_count;
	if (size > spaces_count)
		spaces_count += ft_strlast((char *)s, " \n\t");
	size -= spaces_count;
	if (!(res = ft_memalloc((size_t)size + 1)))
		return (NULL);
	res = ft_strncpy(res, (char *)s + start, size);
	return (res);
}
