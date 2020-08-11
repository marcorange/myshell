/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlota <acarlota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:36:36 by acarlota          #+#    #+#             */
/*   Updated: 2019/11/03 12:31:48 by acarlota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	ih;

	if (!*needle)
		return ((char*)haystack);
	ih = 0;
	while (haystack[ih] != '\0' && ih < len)
	{
		if (haystack[ih] == needle[0])
		{
			i = 1;
			while (needle[i] != '\0' &&
			haystack[i + ih] == needle[i] && (i + ih) < len)
				i++;
			if (needle[i] == '\0')
				return ((char*)&(haystack[ih]));
		}
		ih++;
	}
	return (NULL);
}
