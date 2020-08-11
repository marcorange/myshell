/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlota <acarlota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 13:07:09 by acarlota          #+#    #+#             */
/*   Updated: 2020/05/07 12:00:31 by acarlota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		len;
	char		*str;

	if (s)
	{
		while (*s == ' ' || *s == '\n' || *s == '\t')
			s++;
		len = ft_strlen(s);
		if (len <= 1)
		//	return (ft_strnew(0));
			return ((char*)s);
		while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
			len--;
		str = ft_strnew(len);
		if (!str)
			return (0);
		ft_strncpy(str, s, len);
		return (str);
	}
	return (0);
}
