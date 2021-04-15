/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 13:35:04 by sbauer            #+#    #+#             */
/*   Updated: 2020/12/11 13:52:53 by sbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *s)
{
	int x;

	x = 0;
	while (s[x])
	{
		x++;
	}
	return (x);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	len;
	size_t	i;

	len = 0;
	while (s[len])
		len++;
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*r;
	size_t	i;

	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if (!s || !(r = (char *)malloc(len + 1)))
		return (NULL);
	i = 0;
	while (i < len && s[i])
	{
		r[i] = s[start];
		i++;
		start++;
	}
	r[i] = '\0';
	return (r);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*psrc;
	char	*pdst;
	size_t	i;

	psrc = (char *)src;
	pdst = (char *)dest;
	if (src == dest || !n)
		return (dest);
	if (src < dest)
	{
		i = n;
		while (i-- > 0)
			pdst[i] = psrc[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			pdst[i] = psrc[i];
			i++;
		}
	}
	return (dest);
}
