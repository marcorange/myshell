/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlota <acarlota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 13:20:30 by acarlota          #+#    #+#             */
/*   Updated: 2020/05/16 13:57:10 by acarlota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_list *unset_value(t_list *env, char *name)
{
	char *env_str;
	int not_first_list;
	t_list *prev_list;//nado malloc?
	t_list *head;

	not_first_list = 0;
	prev_list = env;
	head = prev_list;
	while(env)
    {
		env_str = env->content; //pochemu sega bez env_str
        if (ft_strnequ(env_str, name, ft_keylen(env_str)) && ft_strlen(name) == ft_keylen(env_str))
		{	
            ft_strdel(&env_str);
			prev_list->next = env->next; //list eak?
			//lstdel(env)?
			return (head);
		}
		if(not_first_list)
			prev_list = prev_list->next;
        env = env->next;
		not_first_list = 1;
    }
	return (head);
}