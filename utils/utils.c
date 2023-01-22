/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 03:37:02 by kmahdi            #+#    #+#             */
/*   Updated: 2023/01/22 12:59:35 by kmahdi           ###   ########.fr       */
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
		write (1, s, ft_strlen(s));
		return (ft_strlen(s));
	}
	return (ft_putstr("(null)"));
}

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	j;
	int	i;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j <= size)
		{
			if (tab[i] > tab [j])
			{
				ft_swap(&tab[i], &tab[j]);
			}
			j++;
		}
		i++;
	}
}

int	get_nub_len(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nbr;
	char	*result;
	int		total_len;

	nbr = n;
	total_len = get_nub_len(nbr);
	result = (char *) malloc(sizeof(char) * (total_len + 1));
	if (!result)
		return (0);
	result[total_len--] = '\0';
	if (nbr == 0)
		result[0] = '0';
	if (nbr < 0)
	{
		result[0] = '-';
		nbr *= -1;
	}
	while (nbr > 0)
	{
		result[total_len--] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (result);
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
	int j;

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
		exit (1);
	}
	return (res * sym);

}

int	ft_atoi(const char *str)
{
	int					sym;

	sym = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sym *= (-1);
		str++;
	}
	return (count(str, sym));
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] && s2[i]))
	{
		if ((unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}