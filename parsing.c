/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:47:24 by kmahdi            #+#    #+#             */
/*   Updated: 2023/01/22 21:41:49 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_opera(char **argv, int index, int j)
{
	if (argv[index][j] == '-' || argv[index][j] == '+')
	{
		if (argv[index][j + 1] == ' ')
		{
			ft_putstr("Error2 : \n");
			exit(1);
		}
		if (ft_strlen(argv[index]) == 1)
		{
			ft_putstr("Error : one opera : \n");
			exit(1);
		}
	}
}

void	push_to_array(char **argv, int argc, int stack_a[argc - 1])
{
	int	i;
	int	num;
	int	j;

	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		stack_a[i - 1] = num;
		i++;
	}
	i = 1;
	j = 0;
	while (i < argc - 1)
	{
		printf("stack_0 : %d - %d\n",stack_a[i] , stack_a[i - 1]);
		if (stack_a[i - 1] > stack_a[i])
		{
			printf("Error : not suiv:\n");
			exit(1);
		}
		i++;
	}
}

void	check_digits(char **argv, int argc)
{
	int	index;
	int	j;

	index = 1;
	while (index < argc)
	{
		j = 0;
		while (argv[index][j])
		{
			check_opera(argv, index, j);
			if (!ft_isdigit(argv[index][j]))
			{
				ft_putstr("Error: not digit\n");
				exit(1);
			}
			j++;
		}
		index++;
	}
}

void	check_duplicate(int argc, char **argv)

{
	int	index;
	int	j;

	index = 1;
	while (index < argc)
	{
		j = index + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[index], argv[j]) == 0)
			{
				ft_putstr("Error : dupli\n");
				exit(1);
			}
			j++;
		}
		index++;
	}
}
