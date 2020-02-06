/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjinn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:15:09 by cjinn             #+#    #+#             */
/*   Updated: 2019/04/18 19:06:54 by cjinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char i;
	unsigned char *s1;

	s1 = (unsigned char *)s;
	i = (unsigned char)c;
	while (n--)
	{
		if (*s1 == i)
			return (s1);
		s1++;
	}
	return (NULL);
}
