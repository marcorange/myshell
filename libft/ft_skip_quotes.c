/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlota <acarlota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 11:18:01 by acarlota          #+#    #+#             */
/*   Updated: 2020/05/24 15:41:34 by acarlota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int 	quotes_match(char *str)
{
	int	i;
	int	quotes;

	i = 0;
	quotes = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '"')
			quotes++;
		i++;
	}
	if (!(quotes))
		return (-1);
	if (!(quotes % 2))
		return (1);
	return (0);
}

char			*ft_skip_quotes(char *str)
{	
	int			i;
	char		**trimmed;
	char 		*result;

	// if (ft_strequ(str, "\""))
	// 	return (str);

	i = 0;
	if (ft_strchr(str, '"'))
	{
		trimmed = ft_strsplit(str, '"');
		result = (char*)malloc(sizeof(char) * ft_strlen(str) + 1);
		while (trimmed[i])
		{
			result = ft_strjoin(result, trimmed[i++]);
			//free trimmed[i]?
		}
		return (result);
	}
	else
		return (str);
	// return (0);
}
