/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlota <acarlota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 22:33:11 by acarlota          #+#    #+#             */
/*   Updated: 2020/05/25 21:40:46 by acarlota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void display_prompt()
{
    char pwd[BUFF_SIZE]; //buffsize?
    getcwd(pwd, BUFF_SIZE);
    ft_putstr("\x1b[7m\x1b[30m\x1b[41mso\x1b[43msi\x1b[42msk\x1b[44ma-sh\x1b[45mell\x1b[0m:");
    ft_putstr("\x1b[1m\x1b[36m");
    ft_putstr(pwd);
    ft_putstr("\x1b[31m$>\x1b[0m");
}