/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjinn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:27:15 by cjinn             #+#    #+#             */
/*   Updated: 2019/04/18 19:07:03 by cjinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *a;
	unsigned char *a1;

	a = (unsigned char *)s1;
	a1 = (unsigned char *)s2;
	while (n--)
	{
		if (*a != *a1)
			return (*a - *a1);
		a++;
		a1++;
	}
	return (0);
}
