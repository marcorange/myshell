/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlota <acarlota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 13:09:04 by acarlota          #+#    #+#             */
/*   Updated: 2019/11/05 18:16:24 by acarlota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *str, char c)
{
	char	**arr;
	int		j;

	j = 0;
	if (!str || !c)
		return (NULL);
	if (!(arr = (char**)malloc(sizeof(char *) * (ft_strlen(str) + 1))))
		return (NULL);
	arr[0] = NULL;
	while (*str != '\0' && *str == c)
		str++;
	if (*str == '\0')
		return (arr);
	while (*str != '\0')
	{
		if ((str = ft_splitit(str, &arr[j], c)) == NULL)
		{
			ft_freematr(&arr);
			return (arr);
		}
		else if (*str == '\0')
			return (ft_return_arr(arr, ++j));
		j++;
	}
	return (arr);
}
