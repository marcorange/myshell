/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlota <acarlota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:40:17 by acarlota          #+#    #+#             */
/*   Updated: 2020/05/17 20:12:57 by acarlota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/minishell.h"

t_list *set_value(t_list *env, char *name, char *value)
{
	char *env_str;

	t_list *head;
	head = env;
	if(!name)
	{
		ft_putendl("Undefined variable");
		return (0);
	}
	while(head)
    {
		env_str = ft_strdup(head->content);
        if (ft_strnequ(env_str, name, ft_keylen(env_str)) && ft_strlen(name) == ft_keylen(env_str))
        {
			//strdel content? 
			if (!value)
				head->content = ft_strjoin(name, "=");
			else
				head->content = ft_strjoin(ft_strsub(env_str, 0, \
							ft_keylen(env_str) + 1), value);
			return (env);
		}
		if (!(head->next))
		{
			if (!value)
				env_str = ft_strjoin(name, "=");
			else
				env_str = ft_strjoin(ft_strjoin(name, "="), value);
			head->next = ft_lstnew(env_str,  sizeof(char) * \
						(ft_strlen(env_str)));
			return (env);
		}
        head = head->next;
    }
	return (0);
}