/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlota <acarlota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:29:03 by acarlota          #+#    #+#             */
/*   Updated: 2020/04/09 08:35:26 by acarlota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char const	*ft_splitit(const char *str, char **put_in_arr, char c)
{
	int		i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	if (!(*put_in_arr = ft_strndup(str, i)))
		return (NULL);
	while (*str != c)
	{
		if (*str == '\0')
			return ("\0");
		str++;
	}
	while (*str == c)
	{
		str++;
		if (*str == '\0')
			return ("\0");
	}
	return (str);
}
