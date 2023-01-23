/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:47:24 by kmahdi            #+#    #+#             */
/*   Updated: 2023/01/23 07:44:21 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_msg(char *msg)
{
	ft_putstr(msg);
	exit(1);
}

void	check_opera(char **argv, int index, int j)
{
	if (argv[index][j] == '-' || argv[index][j] == '+')
	{
		if (argv[index][j + 1] == ' ')
			exit_msg("Error1 \n");
		if (ft_strlen(argv[index]) == 1)
			exit_msg("Error2 \n");
	}
}

void	push_to_array(char **argv, int argc, t_array *array)
{
	int	i;
	int	is_sorted;

	array->stack_a = malloc(argc * sizeof(int *));
	i = 1;
	printf("%d\n",array->stack_a[i]);
	while (i < argc)
	{
		array->stack_a[i] = ft_atoi(argv[i]);
		i++;
	}
	while (i < argc)
	{
		printf("%d\n",array->stack_a[i]);
		i++;
	}
	is_sorted = 1;
	i = 1;
	while (i < argc)
	{
		if (array->stack_a[i] > array->stack_a[i + 1])
		{
			is_sorted = 0;
			break ;
		}
		i++;
	}
	if (is_sorted != 0)
		exit_msg("Error3 \n");
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
				exit_msg("Error4 \n");
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
				exit_msg("Error5 \n");
			j++;
		}
		index++;
	}
}
