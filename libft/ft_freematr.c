/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freematr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlota <acarlota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:29:52 by acarlota          #+#    #+#             */
/*   Updated: 2019/11/05 16:30:44 by acarlota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freematr(char ***matrix)
{
	int		i;

	i = 0;
	while (*matrix[i])
	{
		ft_strdel(&(*matrix[i]));
		i++;
	}
	free(*matrix);
	*matrix = NULL;
}
