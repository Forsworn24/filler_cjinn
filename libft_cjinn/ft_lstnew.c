/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjinn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:49:49 by cjinn             #+#    #+#             */
/*   Updated: 2019/04/24 16:49:54 by cjinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*rcontent;
	size_t	rsize;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content != NULL)
	{
		rcontent = ft_memalloc(content_size);
		rsize = content_size;
		ft_memcpy(rcontent, content, content_size);
		new->content = rcontent;
		new->content_size = rsize;
	}
	else
	{
		new->content = NULL;
		new->content_size = 0;
	}
	new->next = NULL;
	return (new);
}
