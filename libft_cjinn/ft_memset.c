/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjinn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:14:57 by cjinn             #+#    #+#             */
/*   Updated: 2019/04/18 19:07:35 by cjinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *p;
	unsigned char sum;

	p = (unsigned char *)b;
	sum = (unsigned char)c;
	while (len--)
	{
		*p++ = sum;
	}
	return (b);
}
