/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 03:37:02 by kmahdi            #+#    #+#             */
/*   Updated: 2023/01/22 15:17:27 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_putstr(char *s)
{
	if (s)
	{
		write(1, s, ft_strlen(s));
		return (ft_strlen(s));
	}
	return (ft_putstr("(null)"));
}

int	ft_isdigit(int c)
{
	if (((c >= '0' && c <= '9') || c == '+' || c == '-' || c == ' '))
		return (1);
	else
		return (0);
}

int	count(const char *str, int sym)
{
	unsigned long long	res;
	int					j;

	res = 0;
	j = 0;
	while (ft_isdigit(*str))
	{
		res = 10 * res + (*str - '0');
		if (res > 9223372036854775807 && sym == 1)
			return (-1);
		if (res > 9223372036854775807 && sym == -1)
			return (0);
		str++;
	}
	if (res > 2147483647 && sym == 1)
	{
		ft_putstr("Error : biger then max int \n");
		exit(1);
	}
	return (res * sym);
}

int	ft_atoi(const char *str)
{
	int	sym;

	sym = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sym *= (-1);
		str++;
	}
	return (count(str, sym));
}
