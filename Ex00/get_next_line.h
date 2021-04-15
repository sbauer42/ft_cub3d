/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:05:31 by sbauer            #+#    #+#             */
/*   Updated: 2020/12/11 13:51:17 by sbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 256
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
int		ft_strlen(char *s);
char	*ft_strdup(const char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*join(char *str, char *temp);
int		return_line(char *str, char **line, int i);
int		check_if_eol(char *s);

#endif
