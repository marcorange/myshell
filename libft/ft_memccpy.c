/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlota <acarlota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 13:37:58 by acarlota          #+#    #+#             */
/*   Updated: 2019/04/23 13:38:01 by acarlota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, int c, size_t size)
{
	size_t			i;
	unsigned char	*ptsrc;
	unsigned char	*ptdest;

	ptsrc = (unsigned char *)src;
	ptdest = (unsigned char *)dest;
	i = 0;
	while (i < size)
	{
		ptdest[i] = ptsrc[i];
		if (ptsrc[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
