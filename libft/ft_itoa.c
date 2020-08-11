/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlota <acarlota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 13:32:06 by acarlota          #+#    #+#             */
/*   Updated: 2019/11/05 19:51:09 by acarlota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char		*str;
	size_t		i;
	long		res;

	res = n;
	i = 0;
	if (n < 0 || n == 0)
		i++;
	i = i + ft_intlen(n);
	if (!(str = ft_strnew(i)))
		return (NULL);
	str[i] = '\0';
	if (res == 0)
		str[0] = '0';
	if (res < 0)
	{
		str[0] = '-';
		res = res * -1;
	}
	while (res != 0)
	{
		str[--i] = res % 10 + 48;
		res = res / 10;
	}
	return (str);
}
