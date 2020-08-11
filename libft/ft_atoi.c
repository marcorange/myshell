/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlota <acarlota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 13:47:37 by acarlota          #+#    #+#             */
/*   Updated: 2019/11/03 13:00:28 by acarlota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long	res;
	int		zn;
	int		i;
	long	s;

	res = 0;
	zn = 1;
	i = 0;
	s = 922337203685477580;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			zn = -1;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		if ((res > s || (res == s && str[i] >= '7')) && zn == 1)
			return (-1);
		if ((res > s || (res == s && str[i] >= '8')) && zn == -1)
			return (0);
		res = res * 10 + str[i++] - 48;
	}
	return (res * zn);
}
