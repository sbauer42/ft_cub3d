/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:09:17 by sbauer            #+#    #+#             */
/*   Updated: 2020/12/11 14:06:39 by sbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join(char *str, char *temp)
{
	int		l1;
	int		l2;
	int		i;
	char	*copy;

	if (!str)
		return (ft_strdup(temp));
	if (!temp)
		return (NULL);
	l1 = ft_strlen(str);
	l2 = ft_strlen(temp);
	if (!(copy = (char*)malloc((l1 + l2 + 1))))
		return (NULL);
	i = -1;
	while (str[++i])
		copy[i] = str[i];
	free(str);
	str = NULL;
	i = -1;
	while (temp[++i])
		copy[l1 + i] = temp[i];
	copy[l1 + i] = '\0';
	return (copy);
}

int		return_line(char *str, char **line, int i)
{
	int l;

	*line = ft_substr(str, 0, i);
	i++;
	l = ft_strlen(str + i) + 1;
	ft_memmove(str, str + i, l);
	return (1);
}

int		check_if_eol(char *s)
{
	char	c;
	int		i;

	c = '\n';
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] != c)
		return (-1);
	return (i);
}

int		get_next_line(int fd, char **line)
{
	static char	*str;
	char		temp[BUFFER_SIZE + 1];
	int			i;
	int			ret;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, temp, 0) < 0)
		return (-1);
	if (str && (((i = check_if_eol(str)) != -1)))
		return (return_line(str, line, i));
	while (((ret = read(fd, temp, BUFFER_SIZE)) > 0))
	{
		temp[ret] = '\0';
		str = join(str, temp);
		if (((i = check_if_eol(str)) != -1))
			return (return_line(str, line, i));
	}
	if (str)
	{
		*line = ft_strdup(str);
		free(str);
		str = NULL;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}
