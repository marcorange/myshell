/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlota <acarlota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 08:36:56 by acarlota          #+#    #+#             */
/*   Updated: 2020/05/25 21:41:44 by acarlota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static size_t ft_word_len(char const *s)
{
	size_t word_len;

	word_len = 0;
	while (*s != ' ' && *s != '\t' && *s)
	{
		s++;
		word_len++;
	}
	return (word_len);
}

int len_in_quotes(char const *str)
{
	int len;

	len = 0;
	while (*str != '"')
	{
		str++;
		len++;
	}
	while (*str != ' ' && *str != '\t' && *str != '\0')
	{
		str++;
		len++;
	}
	return (len);
}

int args_num(char const *str)
{
	int count;

	count = 0;
	while (*str)
	{

		while (*str == ' ' || *str == '\t')
			str++;
		if (*str)
		{
			if (*str == '"')
			{
				str++;
				count++;
				str += len_in_quotes(str) + 1;
			}
			else
			{
				count++;
				str += ft_word_len(str);
			}
		}
	}
	return (count);
}

char **ft_split_cmd(char const *s)
{
	char **arr;
	size_t i;

	if (!s)
		return (NULL);
	if (!(arr = (char **)malloc(args_num(s) * sizeof(char *) + 1)))
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == ' ' || *s == '\t')
			s++;
		if (*s)
		{
			if (*s == '"')
			{
				s++;
				arr[i] = ft_strsub(s, 0, len_in_quotes(s));
				s += len_in_quotes(s) + 1;
			}
			else
			{
				arr[i] = ft_strsub(s, 0, ft_word_len(s));
				s += ft_word_len(s);
			}
			if (!arr[i])
			{
				ft_putstr("memalloc error");
				ft_free_tab(arr, i);
				return (NULL);
			}
			i++;
		}
	}
	arr[i] = NULL;
	return (arr);
}