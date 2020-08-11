/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlota <acarlota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 12:45:15 by acarlota          #+#    #+#             */
/*   Updated: 2020/05/25 21:53:35 by acarlota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void echo_builtin(t_env *lst)
{
	int i;

	i = 1;
	expand_args(lst);
	while(lst->cmd_arg[i])
	{
		if (lst->cmd_arg[i][0] != '\0')
		{
				ft_putstr(lst->cmd_arg[i]);
				ft_putchar(' ');
		}
		i++;
	}
	ft_putchar('\n');
}
