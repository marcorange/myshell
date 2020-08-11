/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlota <acarlota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 20:11:14 by acarlota          #+#    #+#             */
/*   Updated: 2020/05/23 19:34:53 by acarlota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int cd_builtin(t_env *lst)
{
	char cwd[500]; //так можно? как правильно посчитать размер путь 
	if (lst->cmd_arg[1] && lst->cmd_arg[2])
	{
		ft_putendl("slishkom mnogo arg");
		return (0);
	}
	getcwd(cwd, 500);
	if(ft_strequ(lst->cmd_arg[1], "-"))
	{   
		if(!(get_value(lst->env_list, "$OLDPWD")))
		{
			ft_putendl("OLDPWD is not defined");
			return (0);
		}
		else
		{
			chdir(get_value(lst->env_list, "$OLDPWD"));
			set_value(lst->env_list, "OLDPWD", cwd);
		}
	}
	
	else if (!lst->cmd_arg[1] || ft_strequ(lst->cmd_arg[1], "~"))
		chdir(get_value(lst->env_list, "$HOME"));
	else
	{
	if (ft_strchr(lst->cmd_arg[1], '~'))
		lst->cmd_arg[1] = home_expansion(lst->env_list, lst->cmd_arg[1]); 
	if (ft_strchr(lst->cmd_arg[1], '$'))
		lst->cmd_arg[1] = key_expansion(lst->env_list, lst->cmd_arg[1]);
	if (lst->cmd_arg[1] && !cd_errors(lst->cmd_arg[1]))
		chdir(lst->cmd_arg[1]); //почему работает ".." ? 
	}
	set_value(lst->env_list, "OLDPWD", cwd);
	getcwd(cwd, BUFF_SIZE);
	set_value(lst->env_list, "PWD", cwd);
	return (0);
}