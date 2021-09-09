/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 12:34:41 by aamorin-          #+#    #+#             */
/*   Updated: 2021/08/27 10:54:22 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	check_duplicate(char *str, char c, int i)
{
	int	count;

	count = 0;
	while (i >= 0)
	{
		if (str[i] == c)
			count++;
		i--;
	}
	if (count > 1)
		return (0);
	return (1);
}

int	check_exits(char *str, char c, int i)
{
	int	count;

	count = 0;
	while (i >= 0)
	{
		if (str[i] == c)
			count++;
		i--;
	}
	if (count > 0)
		return (0);
	return (1);
}

void	ft_union(char *str1, char *str2)
{
	int	i;
	int	k;

	i = 0;
	while (str1[i] != '\0')
	{
		if (check_duplicate(str1, str1[i], i))
			write (1, &str1[i], 1);
		i++;
	}
	k = 0;
	while (str2[k] != '\0')
	{
		if (check_duplicate(str2, str2[k], k) && check_exits(str1, str2[k], i))
			write (1, &str2[k], 1);
		k++;
	}
}

int	main(int a, char **argv)
{
	if (a == 3)
		ft_union(argv[1], argv[2]);
	write (1, "\n", 1);
	return (1);
}
