/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlota <acarlota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 16:36:33 by acarlota          #+#    #+#             */
/*   Updated: 2020/04/10 16:36:39 by acarlota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*newlist;

	if (!(newlist = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		newlist->content_size = 0;
		newlist->content = NULL;
	}
	else
	{
		if (!(newlist->content = malloc((sizeof(content)) * (content_size))))
		{
			free(newlist);
			newlist = NULL;
			return (NULL);
		}
		newlist->content_size = content_size;
		newlist->content = ft_memcpy(newlist->content, content, content_size);
		newlist->content_size = content_size;
	}
	newlist->next = NULL;
	return (newlist);
}