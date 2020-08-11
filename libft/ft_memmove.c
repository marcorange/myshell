/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlota <acarlota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 13:26:31 by acarlota          #+#    #+#             */
/*   Updated: 2019/11/03 12:07:39 by acarlota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptsrc;
	unsigned char	*ptdst;
	size_t			i;

	i = 0;
	ptsrc = (unsigned char*)src;
	ptdst = (unsigned char*)dst;
	if (src == dst)
		return (dst);
	if (src < dst)
	{
		while (len-- > 0)
			ptdst[len] = ptsrc[len];
	}
	else
		while (i < len)
		{
			ptdst[i] = ptsrc[i];
			i++;
		}
	return (dst);
}
