/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlota <acarlota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 13:39:17 by acarlota          #+#    #+#             */
/*   Updated: 2019/10/28 17:18:50 by acarlota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *ptr;
	unsigned char *ptr2;

	if (dest == NULL && src == NULL)
		return (dest);
	ptr = (unsigned char*)dest;
	ptr2 = (unsigned char*)src;
	while (n-- > 0)
		*ptr++ = *ptr2++;
	return (dest);
}
