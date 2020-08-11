/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlota <acarlota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 18:48:20 by acarlota          #+#    #+#             */
/*   Updated: 2020/05/25 21:37:46 by acarlota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int				cd_errors(char *path) //+loop
{
	if (open(path, __O_DIRECTORY) < 0)
	{		
		if (access(path, F_OK) == -1)
		{
			ft_putstr(path);
			ft_putendl(": no such file or directory");
		}
		else if (access(path, X_OK) == -1)
		{
			ft_putstr(path);
			ft_putendl(": permission denied");
		}
		else
		{
			ft_putstr(path);
			ft_putendl(": not a directory");
		}
		return (-1);
	}
	return (0);
}