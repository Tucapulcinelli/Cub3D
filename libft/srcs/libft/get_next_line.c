/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbertali <sbertali@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 18:11:39 by sbertali          #+#    #+#             */
/*   Updated: 2021/05/07 19:38:10 by sbertali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/resource.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

static char		*ft_find_nl(char **temp)
{
	char		*stock_long;
	char		*memory;

	memory = NULL;
	stock_long = ft_strdup_gnl((char*)temp);
	if (ft_strchr_gnl(*temp, '\n'))
	{
		free(stock_long);
		stock_long = NULL;
		stock_long = ft_strsub_gnl(*temp, 0, (ft_strlen_gnl(*temp)\
						- ft_strlen_gnl((char*)ft_strchr_gnl(*temp, '\n'))));
		memory = ft_strdup_gnl(ft_strchr_gnl(*temp, '\n') + 1);
		free(*temp);
		*temp = NULL;
		*temp = (char *)ft_strdup_gnl(stock_long);
	}
	free(stock_long);
	return (memory);
}

char			*ft_join_free_gnl(char *s1, char *s2)
{
	char		*tmp;

	tmp = ft_strdup_gnl(s1);
	free(s1);
	s1 = ft_strjoin_gnl(s2, tmp);
	free(tmp);
	free(s2);
	s2 = NULL;
	return (s1);
}

static int		ft_read(int fd, char **temp)
{
	char		buffer[BUFFER_SIZE + 1];
	int			check;
	int			ret;
	char		*tmp;

	ret = 1;
	check = 1;
	while ((ret > 0) && check == 1)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret < 0)
			return (-1);
		buffer[ret] = '\0';
		if (*temp)
		{
			tmp = ft_strdup_gnl(*temp);
			free(*temp);
			*temp = ft_strjoin_gnl(tmp, buffer);
			free(tmp);
		}
		else
			*temp = ft_strdup_gnl(buffer);
		check = ((ft_strchr_gnl(buffer, '\n')) ? 0 : 1);
	}
	return (ret);
}

int				str_free(char *str, int i)
{
	free(str);
	return (i);
}

int				get_next_line(const int fd, char **line)
{
	char		*temp;
	static char	*memor;
	int			ret;

	temp = ft_strdup_gnl("\0");
	ret = ft_read(fd, &temp);
	if (ret < 0 || fd < 0 || !(line) || BUFFER_SIZE <= 0)
		return (str_free(temp, -1));
	temp = (memor != NULL) ? ft_join_free_gnl(temp, memor) : temp;
	memor = NULL;
	if ((ret == 0 && !ft_strchr_gnl(temp, '\n') && !ft_strchr_gnl(memor, '\n')))
	{
		*line = ft_strdup_gnl(temp);
		return (str_free(temp, 0));
	}
	if (ret >= 0)
	{
		memor = ft_find_nl(&temp);
		*line = ft_strdup_gnl(temp);
	}
	return (str_free(temp, 1));
}

char					*ft_strsub_gnl(char *str, int start, int len)
{
	int					i;
	char				*output;

	i = 0;
	if (!str)
		return (NULL);
	if (!(output = ft_calloc(1, sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len && (str[start + i] != '\n'))
	{
		output[i] = str[start + i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

size_t					ft_strlen_gnl(const char *s)
{
	int					i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char					*ft_strchr_gnl(const char *s, int c)
{
	int					i;
	char				*tmp;

	i = 0;
	tmp = (char *)s;
	if (!s)
		return (NULL);
	if (c == '\0')
	{
		while (*tmp)
			tmp++;
		return ((char*)tmp);
	}
	while (tmp[i] != '\0')
	{
		if (tmp[i] == (char)c)
			return ((char *)&tmp[i]);
		i++;
	}
	if (*tmp == '\0' && c == '\0')
	{
		return (tmp);
	}
	return (NULL);
}

char					*ft_strdup_gnl(const char *s1)
{
	char				*output;
	int					i;
	int					size;

	if (!s1)
		return (NULL);
	size = ft_strlen_gnl(s1);
	if (!(output = ft_calloc(1, sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while ((char)s1[i])
	{
		output[i] = s1[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

char					*ft_strjoin_gnl(char const *s1, char const *s2)
{
	unsigned long		i;
	char				*output;
	unsigned long		size1;
	unsigned long		size2;

	if (!(s1 && s2))
		return (NULL);
	size1 = ft_strlen_gnl(s1);
	size2 = ft_strlen_gnl(s2);
	if (!(output = ft_calloc(1, sizeof(char) * (size1 + size2 + 1))))
		return (NULL);
	i = 0;
	while (i < size1)
	{
		output[i] = s1[i];
		i++;
	}
	while (i < size1 + size2)
	{
		output[i] = s2[i - size1];
		i++;
	}
	output[i] = '\0';
	return (output);
}
