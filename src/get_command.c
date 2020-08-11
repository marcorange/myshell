/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlota <acarlota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 15:31:18 by acarlota          #+#    #+#             */
/*   Updated: 2020/05/25 21:39:14 by acarlota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int get_command(t_env *lst)
{
	display_prompt();
	size_t i = 0;
	if ((get_next_line(0, &lst->cmd_line)) == -1)
		return(0);
	if (lst->cmd_line[0] == '\0')
		return (0);
	while (lst->cmd_line[i] == '\t' || lst->cmd_line[i] == ' ')
	{
		if (i++ == ft_strlen(lst->cmd_line) - 1)
			return(0);
	}
    if(ft_strlen(lst->cmd_line) >= 1)
    {	
		// if (quotes_match(lst->cmd_line) == 1) // && !no_whitespaces(lst->cmd_line))
		// 	lst->cmd_arg = ft_strsplit(lst->cmd_line, '"');
		// else
		if (!(quotes_match(lst->cmd_line)))
		{
			ft_putendl("Unmatched \".");
			return (0);
		}
		if (!(lst->cmd_arg = ft_split_cmd(lst->cmd_line)))
			return (0); //why trim?
		i = 0;
		while (lst->cmd_arg[i])
		{
			lst->cmd_arg[i] = ft_skip_quotes(lst->cmd_arg[i]);
			i++;
		}
        lst->cmd_name = ft_strdup(ft_strtrim(lst->cmd_arg[0]));
        return (1);
    }
    cmd_not_found_msg(ft_strtrim(lst->cmd_line));
    return (0);
}
