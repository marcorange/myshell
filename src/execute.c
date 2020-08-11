/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlota <acarlota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 09:37:19 by acarlota          #+#    #+#             */
/*   Updated: 2020/05/25 21:38:45 by acarlota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int    sh_builtins(t_env *lst)
{
	if (ft_strequ("exit", lst->cmd_name))
	{
    	// system("aplay /home/acarlota/minishell/bye.wav"); //pwd
		exit (0);
	}
	else if ((ft_strequ("env", lst->cmd_name)))
		env_builtin(lst);
	else if ((ft_strequ("echo", lst->cmd_name)))
		echo_builtin(lst);
	else if ((ft_strequ("setenv", lst->cmd_name)))
		ft_setenv(lst);
	else if ((ft_strequ("unsetenv", lst->cmd_name)))
		ft_unsetenv(lst);
	else if ((ft_strequ("cd", lst->cmd_name)))
		cd_builtin(lst);
	else
		return (0);
	return (1);
}

void expand_args(t_env *lst)
{
	int i = 0;
	while(lst->cmd_arg[i]) //core
	{
		if (ft_strchr(lst->cmd_arg[i], '~'))
			lst->cmd_arg[i] = home_expansion(lst->env_list, lst->cmd_arg[i]);
		if (ft_strchr(lst->cmd_arg[i], '$'))
			lst->cmd_arg[i] = key_expansion(lst->env_list, lst->cmd_arg[i]);
		i++;
	}
}

void update_envcpy(t_env *lst)
{
	t_list *tmp;
	int		i;

	i = 0;
	tmp = lst->env_list;
	lst->envcpy = (char**)malloc(sizeof(char*)); //почему так работает
	while (tmp)
	{
		lst->envcpy[i] = ft_strdup(tmp->content);
		i++;
		tmp = tmp->next;
	}
	lst->envcpy[i] = NULL;
}

void sh_executable(t_env *lst)
{
	int i = 0;
    lst->path = ft_strsplit(get_value(lst->env_list, "$PATH"), ':');
	expand_args(lst);
	update_envcpy(lst);
	if (!lst->path)
	{
		execve(lst->cmd_name, lst->cmd_arg, lst->envcpy);
		ft_putendl("PATH is not defined");
		return ;
	}
	while (lst->path[i])
	{
		lst->path[i] = ft_strjoin(lst->path[i], "/");
		if (ft_strnequ(lst->path[i], lst->cmd_name, ft_strlen(lst->path[i])))
			execve(lst->cmd_name, lst->cmd_arg, lst->envcpy);
		else
			execve(ft_strjoin(lst->path[i], lst->cmd_name), lst->cmd_arg, lst->envcpy);
		i++;
	}
	cmd_not_found_msg(lst->cmd_name);
}