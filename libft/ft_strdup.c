/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlota <acarlota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:26:16 by acarlota          #+#    #+#             */
/*   Updated: 2019/12/04 10:10:13 by acarlota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		len;
	char	*dst;

	len = ft_strlen(src);
	dst = (char*)malloc(sizeof(*dst) * (len + 1));
	if (!dst)
		return (NULL);
	ft_strcpy(dst, src);
	return (dst);
}
