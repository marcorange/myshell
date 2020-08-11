/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlota <acarlota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 17:12:23 by acarlota          #+#    #+#             */
/*   Updated: 2020/05/22 17:15:10 by acarlota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char **ft_arrdup(char **arr)
{
	char **res;
	int i;

	i = 0;
	while (arr[i])
		i++;
	if (!(res = (char**)malloc(sizeof(char*) * i)))
        return (NULL);
	i = 0;
	while (arr[i])
	{
		res[i] = ft_strdup(arr[i]); //if !malloc
		i++;
	}
	res[i] = NULL;
	return (res);
}