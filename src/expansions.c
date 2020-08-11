/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlota <acarlota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 12:03:31 by acarlota          #+#    #+#             */
/*   Updated: 2020/05/26 00:19:27 by acarlota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char *home_expansion(t_list *env, char *str)
{
	int i = 0;
	char *user;
	char *result;

	if(str[0] == '$')
	{
		if (!(get_value(env, str)))
			return (ft_strchr(str, '~'));
		return (str);
	}
	if (ft_strnequ(str, "~/", 2))
        return(ft_strjoin(get_value(env, "$HOME"), ++str));
	user = get_value(env, "$USER");
	if(ft_strequ(str, "~") || ft_strequ(str, ft_strjoin("~", user)))
		return (result = get_value(env, "$HOME"));
	result = ft_strdup(str);
	if (ft_strlen(ft_strchr(str, '~')) == 1 &&
		ft_strchr(str, '=') && *(ft_strchr(str, '=') + 1) == '~')
	{
		while (result[i] != '~')
			i++;
		result[i] = '\0';
		result = ft_strjoin(result, get_value(env, "$HOME"));
	}
	return (result);
}

char *key_expansion(t_list *env, char *str)
{
	char *value = NULL;
	int i = 0;
	value = ft_strdup(str);
	while (*value++ != '$')
		i++;
	if(!ft_is_sign(str[i + 1]))
		str[i] = '\0';
	value = get_value(env, --value);
	if (value)
		return (str = ft_strjoin(str, value));
	return (str);
}

// 	if(!value)
// 	{
// 		if(ft_is_sign(str[i + 1]))
// 			ft_putendl("Illegal variable name.");
// 		else 
// 		{
// 			ft_putstr(str + 1);
// 			ft_putendl(": Undefined variable.");
// 		}
// 		return (0);
// 	}
