/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlota <acarlota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 15:33:07 by acarlota          #+#    #+#             */
/*   Updated: 2020/05/25 23:46:21 by acarlota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void exit_sh(char *cmd) //как работает exit: есть остановленные задания
{
	if (ft_strequ("exit", cmd))
		exit(0);
}

void cmd_not_found_msg(char *cmd)
{
	ft_putstr(cmd);
	ft_putendl(": commmad not found");
	exit (0);
}

size_t	ft_keylen(char *content)
{
	size_t i;

	i = 0;
	while (content[i] != '=')
			i++;
	return (i);
}

void	printenv(t_env *print)
{
	t_list	*tmp;

	tmp = print->env_list;
	while (tmp)
	{
		ft_putstr(tmp->content);
		if(tmp->next)
			ft_putchar('\n');
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

char ft_is_sign(char c)
{
	return (c == '~' || c == '@' || c == '#' || c == '%' || \
			c == '^' || c == '&' || c == '*' || c == '-' || c == '+' || \
			c == '=' || c == ' ' || c == '\t' || c == '$');
}

