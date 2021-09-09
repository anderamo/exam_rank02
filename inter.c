/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 12:23:30 by aamorin-          #+#    #+#             */
/*   Updated: 2021/08/26 12:33:36 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	inter(char *str1, char *str2)
{
	int	i;
	int	k;

	i = 0;
	while (str1[i] != '\0')
	{
		k = 0;
		while (str2[k] != '\0')
		{
			if (str1[i] == str2[k])
			{
				if (check_duplicate(str1, str1[i], i))
				{
					write (1, &str1[i], 1);
					break ;
				}
			}
			k++;
		}
		i++;
	}
}

int	main(int a, char **argv)
{
	if (a == 3)
		inter(argv[1], argv[2]);
	write (1, "\n", 1);
	return (1);
}
