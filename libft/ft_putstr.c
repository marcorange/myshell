/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlota <acarlota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:14:26 by acarlota          #+#    #+#             */
/*   Updated: 2019/05/06 15:32:42 by acarlota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char *str)
{
	int indx;

	if (!str)
		return ;
	indx = 0;
	while (str[indx] != '\0')
	{
		ft_putchar(str[indx]);
		indx++;
	}
}
