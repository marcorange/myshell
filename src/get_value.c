/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlota <acarlota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 15:14:52 by acarlota          #+#    #+#             */
/*   Updated: 2020/05/26 00:22:31 by acarlota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char *get_value(t_list *env, char *name)
{
	size_t key_len = 0;
	char *value;
	char *tail;
	char *signs = (char*)malloc(sizeof(char) * ft_strlen(name));
	t_list *tmp_lst; // = (t_list*)malloc(sizeof(t_list)); 

	tmp_lst = env;
	if (!(ft_is_sign(name[0]))) //zdes i v ftsign add $
		return (NULL);
	while (name[0] != '$' && *name != '\0')
		signs[key_len++] = *name++;
	signs[key_len] = '\0';
	if (*name == '$')
	{	
		name++;
		while(tmp_lst)
		{
			value = ft_strdup(tmp_lst->content);
			key_len = ft_keylen(value);
    	    if (ft_strnequ(value, name, key_len))
    	    {
				if (ft_strlen(name) > key_len && ft_is_sign(*(name + key_len))) //zdes
					tail = ft_strdup(name + key_len); 
				else if (ft_strlen(name) > key_len && !ft_is_sign(*(name + key_len)))
					return (signs);
				else
					tail = NULL; 
				value += key_len + 1;
				value = ft_strjoin(signs, value); 
				if (tail)
				{
					if((tail = get_value(env, tail)))
						value = (ft_strjoin(value, tail));
					else 
						return (0);
				}
				return (value);
			}
        	tmp_lst = tmp_lst->next;
    	}
		return (0); 
	}
	return (ft_strjoin(signs, name));
}