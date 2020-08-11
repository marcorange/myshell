/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_things.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlota <acarlota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 18:42:01 by acarlota          #+#    #+#             */
/*   Updated: 2020/05/23 17:20:59 by acarlota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	env_to_list(t_env *dest, char **env)
{
	int		i;
	t_list	*tmp;

	i = 0;
	if (env[i])
	{
		dest->env_list = ft_lstnew(env[i], sizeof(char) * (ft_strlen(env[i]) + 1));
		i++;
	}
	tmp = dest->env_list;
	while (env[i])
	{
		tmp->next = ft_lstnew(env[i],  sizeof(char) * (ft_strlen(env[i])));
		i++;
		tmp = tmp->next;
	}
}

t_env		*init_list(char **env)
{
	t_env *new;
	if (!(new = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	new->status =0;
	new->cmd_line = NULL;
	new->cmd_name = NULL;
	new->cmd_arg = NULL;
	new->parent = 0;
	new->path = NULL;
	env_to_list(new, env);
	// unset_value(new->env_cpy, "OLDPWD"); jako subshell?
	return (new);
}