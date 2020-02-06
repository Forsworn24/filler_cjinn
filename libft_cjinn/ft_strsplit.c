/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjinn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:15:10 by cjinn             #+#    #+#             */
/*   Updated: 2019/04/18 20:15:45 by cjinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_words_sep(char const *s, char c)
{
	int count;
	int sep;

	sep = 0;
	count = 0;
	while (*s != '\0')
	{
		if (sep == 1 && *s == c)
			sep = 0;
		if (sep == 0 && *s != c)
		{
			sep = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static size_t	ft_strlen_sep(char const *s, char c)
{
	int len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		nb_words;
	size_t	len;

	if (!s)
		return (NULL);
	i = 0;
	nb_words = ft_count_words_sep(s, c);
	if (!(str = ((char**)malloc(sizeof(*str) * (nb_words + 1)))))
		return (NULL);
	while (nb_words--)
	{
		while (*s != '\0' && *s == c)
			s++;
		len = ft_strlen_sep(s, c);
		str[i] = ft_strsub(s, 0, len);
		if (str[i] == '\0')
			return (NULL);
		s = s + ft_strlen_sep(s, c);
		i++;
	}
	str[i] = NULL;
	return (str);
}
