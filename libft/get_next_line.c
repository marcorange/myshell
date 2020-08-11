/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlota <acarlota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:36:01 by acarlota          #+#    #+#             */
/*   Updated: 2020/04/06 11:07:39 by acarlota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *findnl(char *tail, char **line)
{
	char *nl;

	nl = NULL;
	if (tail)
		if ((nl = ft_strchr(tail, '\n')))
		{
			*nl = '\0';
			*line = ft_strdup(tail);
			ft_strcpy(tail, ++nl);
		}
		else
		{
			*line = ft_strdup(tail);
			ft_strclr(tail);
		}
	else
		*line = ft_strnew(1);
	return (nl);
}

int get_line(const int fd, char **line, char **tail)
{
	int count;
	char buf[BUFF_SIZE + 1];
	char *nlptr;
	char *leak;

	nlptr = findnl(*tail, line);
	while (!nlptr && (count = read(fd, buf, BUFF_SIZE)))
	{
		buf[count] = '\0';
		if ((nlptr = ft_strchr(buf, '\n')))
		{
			*nlptr = '\0';
			nlptr++;
			leak = *tail;
			if (!(*tail = ft_strdup(nlptr)))
				ft_strdel(tail);
			ft_strdel(&leak);
		}
		leak = *line;
		if (!(*line = ft_strjoin(*line, buf)) || count < 0)
			return (-1);
		ft_strdel(&leak);
	}
	return (count || ft_strlen(*line)) ? 1 : 0; //wtf
}

t_gnl *newlist(int fd)
{
	t_gnl *new;

	new = (t_gnl *)malloc(sizeof(t_gnl));
	new->fd = fd;
	new->tail = NULL;
	new->next = NULL;
	return (new);
}

int get_next_line(int fd, char **line)
{
	static t_gnl *head;
	t_gnl *tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	if (head == NULL)
		head = newlist(fd);
	tmp = head;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = newlist(fd);
		tmp = tmp->next;
	}
	return (get_line(tmp->fd, line, &tmp->tail));
}
