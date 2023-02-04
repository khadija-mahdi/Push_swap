/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:47:24 by kmahdi            #+#    #+#             */
/*   Updated: 2023/02/04 01:24:18 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_opera(char **argv, int index, int j)
{
	if (argv[index][j] == '-' || argv[index][j] == '+')
	{
		if (argv[index][j + 1] == ' ')
			exit_msg("Error\n");
		if (ft_strlen(argv[index]) == 1)
			exit_msg("Error\n");
	}
	else if (!ft_isdigit(argv[index][j]))
		exit_msg("Error\n");
}

void	check_sorted(int argc, t_array *array)
{
	int	i;
	int	is_sorted;

	is_sorted = 1;
	i = 0;
	while (i < argc - 2)
	{
		if (array->stack_a[i] > array->stack_a[i + 1])
		{
			is_sorted = 0;
			break ;
		}
		i++;
	}
	if (is_sorted == 1)
		exit(0);
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
			if (j == 0)
				check_opera(argv, index, j);
			else if (!ft_isdigit(argv[index][j]))
				exit_msg("Error\n");
			j++;
		}
		index++;
	}
}

void	check_duplicate(t_array *stacks)

{
	int	index;
	int	j;

	index = 0;
	while (index < stacks->size_a)
	{
		j = index + 1;
		while (j < stacks->size_a)
		{
			if (stacks->stack_a[index] == stacks->stack_a[j])
				exit_msg("Error\n");
			j++;
		}
		index++;
	}
}
