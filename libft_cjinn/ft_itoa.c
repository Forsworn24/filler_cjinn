/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjinn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:28:57 by cjinn             #+#    #+#             */
/*   Updated: 2019/05/01 17:02:01 by cjinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_str_len(int nb)
{
	size_t	i;

	i = 1;
	while (nb /= 10)
		i++;
	return (i);
}

char		*ft_itoa(int n)
{
	char			*str;
	size_t			len;
	unsigned int	nb;

	len = ft_str_len(n);
	nb = n;
	if (n < 0)
	{
		nb = -n;
		len++;
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[--len] = nb % 10 + '0';
	while (nb /= 10)
		str[--len] = nb % 10 + '0';
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
