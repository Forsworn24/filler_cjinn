/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjinn <cjinn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:37:38 by cjinn             #+#    #+#             */
/*   Updated: 2020/02/04 20:20:11 by cjinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen((char *)s);
	if (!(new = (char *)malloc(len * sizeof(*new) + 1)))
		return (NULL);
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
