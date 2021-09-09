/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 19:02:31 by aamorin-          #+#    #+#             */
/*   Updated: 2021/09/08 20:12:49 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

unsigned int ft_w_str(char *str)
{
	unsigned int i;

	i = 0;
	if (str == NULL)
		str = "(null)";
	while (str[i] != '\0')
		i++;
	write (1, str, i);
	return (i);
}

unsigned int ft_w_hex(unsigned int number)
{
	unsigned long long num;
	int i;
	char *str;
	int size;

	i = 0;
	num = number;
	if (number == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (number != 0)
	{
		number /= 16;
		i++;
	}
	size = i;
	str = malloc(i + 1);
	str[i] = '\0';
	while (num != 0)
	{
		if ((num % 16) < 10)
			str[i - 1] = (num % 16) + 48;
		else
			str[i - 1] = (num % 16) + 87;
		i--;
		num /= 16;
	}
	write (1, str , size);
	free (str);
	return (size);
}

unsigned int ft_w_int(int number)
{
	long		n;
	int		i;
	char	*str;
	int		size;

	if (number == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	i = 0;
	n = number;
	while (number != 0)
	{
		number /= 10;
		i++;
	}
	if (n < 0)
	{
		i++;
		str = malloc(i + 1);
		str[0] = '-';
		n *= -1;
	}
	else
		str = malloc(i + 1);
	str[i] = '\0';
	while (n != 0)
	{
		str[i - 1] = (n % 10) + '0';
		i--;
		n /= 10;
	}
	size = strlen(str);
	write (1, str, size);
	free (str);
	return (size);
}

unsigned int specificer(char *str, va_list ap)
{
	unsigned int count;

	count = 0;
	if (*str == 'd')
		count = ft_w_int(va_arg(ap, int));
	if (*str == 'x')
		count = ft_w_hex(va_arg(ap, unsigned int));
	if (*str == 's')
		count = ft_w_str(va_arg(ap, char *));
	return (count);
}

int	ft_printf(const char *nargs, ...)
{
	va_list			ap;
	unsigned int	count;

	count = 0;
	va_start(ap, nargs);
	while (*nargs)
	{
		if (*nargs == '%' && *++nargs != '%')
			count += specificer((char *)nargs, ap);
		else
		{
			write(1, nargs, 1);
			count++;
		}
		nargs++;
	}
	va_end(ap);
	return (count);
}
