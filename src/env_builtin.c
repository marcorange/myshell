/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlota <acarlota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 14:02:23 by acarlota          #+#    #+#             */
/*   Updated: 2020/05/22 16:40:18 by acarlota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void env_builtin(t_env *lst)
{
	if (ft_strequ(lst->cmd_name, "env"))
		printenv(lst);
}

int ft_setenv(t_env *lst)
{
	int i = 1;
	if (!(lst->cmd_arg[1]))
		printenv(lst);
	else if (lst->cmd_arg[1] && lst->cmd_arg[2] && lst->cmd_arg[3])
		ft_putendl("Too many arguments");
	else
	{
		while (i < 3) //ft_core starts
		{
			if (lst->cmd_arg[i])
			{
				if (ft_strchr(lst->cmd_arg[i], '~') && i > 1)
					lst->cmd_arg[i] = home_expansion(lst->env_list, lst->cmd_arg[i]);
				if (ft_strchr(lst->cmd_arg[i], '$'))
					lst->cmd_arg[i] = key_expansion(lst->env_list, lst->cmd_arg[i]);
			}
			i++;
		}
		lst->env_list = set_value(lst->env_list, lst->cmd_arg[1], lst->cmd_arg[2]);
	}
	return (0);
}

int ft_unsetenv(t_env *lst)
{
	int i;
	
	i = 1;
	if (!(lst->cmd_arg[1]))
		ft_putendl("Too few arguments");
	while (lst->cmd_arg[i])
	{
		if (ft_strchr(lst->cmd_arg[i], '~') && i > 1)
			lst->cmd_arg[i] = home_expansion(lst->env_list, lst->cmd_arg[i]);
		if (ft_strchr(lst->cmd_arg[i], '$'))
			lst->cmd_arg[i] = key_expansion(lst->env_list, lst->cmd_arg[i]);
		lst->env_list = unset_value(lst->env_list, lst->cmd_arg[i++]);
	}
	return (0);
}