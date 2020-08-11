/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlota <acarlota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:00:53 by acarlota          #+#    #+#             */
/*   Updated: 2019/11/03 12:23:03 by acarlota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *haystack, char const *needle)
{
	int	n;
	int	cmp;

	n = ft_strlen(needle);
	if (!*needle)
		return ((char*)haystack);
	while (*haystack)
	{
		cmp = ft_strncmp(haystack, needle, n);
		if (cmp == 0)
			return ((char*)haystack);
		haystack++;
	}
	return (0);
}
