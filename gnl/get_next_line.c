/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:27:15 by aamorin-          #+#    #+#             */
/*   Updated: 2021/09/09 10:46:01 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int ft_strlen(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while(str[i] != '\0')
		i++;
	return (i);
}

char *ft_strjoin(char *s1, char *s2)
{
	int	total;
	int size1;
	int size2;
	char *join;
	int i;

	i = 0;
	if (!s1)
	{
		join = malloc(ft_strlen(s2) + 1);
		while (s2[i])
		{
			join[i] = s2[i];
			i++;
		}
		join[i] = '\0';
		return (join);
	}
	if (!s2)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	total = size1 + size2;
	join = malloc(total + 1);
	while (s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	size1 = 0;
	while (s2[size1] != '\0')
	{
		join[i] = s2[size1];
		i++;
		size1++;
	}
	join[i] = '\0';
	free(s1);
	return (join);
}

int	ft_EOF(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while(str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char *ft_save(char *text)
{
	char *str1;
	int i;
	int j;

	if (!text)
		return (NULL);
	i = 0;
	while (text[i] && text[i] != '\n')
		i++;
	if (!text[i])
	{
		free(text);
		return (NULL);
	}
	str1 = malloc ((i + 1) * (ft_strlen(text) - i) + 1);
	if (!str1)
		return (NULL);
	i++;
	j = 0;
	while (text[i])
		str1[j++] = text[i++];
	str1[j] = '\0';
	free (text);
	return (str1);
}

char *ft_read_file(char *str)
{
	char *str1;
	int i;

	if (!str || str[0] == '\0')
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	i++;
	str1 = malloc(i + 1);
	if (!str1)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		str1[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		str1[i++] = '\n';
	str1[i] = '\0';
	return (str1);
}

char	*get_next_line(int fd)
{
	char *buf;
	int	size;
	char *line;
	static char *text;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	size = 1;
	while (size != 0 && ft_EOF(text) == 0)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[size] = '\0';
		text = ft_strjoin(text, buf);
	}
	free(buf);
	line = ft_read_file(text);
	text = ft_save(text);
	return (line);
}


