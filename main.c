/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 03:28:30 by kmahdi            #+#    #+#             */
/*   Updated: 2023/01/25 06:46:30 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_array	*init_stacks(int argc, char **argv)
{
	t_array	*array;
	int		i;
	int		j;

	array = malloc(sizeof(t_array));
	if (!array)
		exit_msg("ERROR maloc !!");
	array->stack_b = malloc((argc - 1) * sizeof(int *));
	//array->stack_b = NULL;
	array->new_stack = malloc((argc - 1) * sizeof(int *));
	array->stack_a = malloc((argc - 1) * sizeof(int *));
	i = 1;
	j = 0;
	while (j < argc - 1)
	{
		if (argv[i][0] == '\0')
			exit_msg("Error_empty \n");
		array->stack_a[j] = ft_atoi(argv[i]);
		array->stack_b[j] = 0;
		i++;
		j++;
	}
	return (array);
}
void	print_stacks(t_array *stacks, int argc)
{
	printf("-------------------------------\n");
	int j = 0;
	while (j < argc - 1)
	{
		printf("stack_b  ---->: %d\n", stacks->stack_b[j]);
		j++;
	}
	printf("-------------------------------\n");
	j = 0;
	while (j < argc - 1)
	{
		printf("stack_a  ---->: %d\n", stacks->stack_a[j]);
		j++;
	}
	printf("-------------------------------\n");
}

int	main(int argc, char **argv)
{
	t_array	*stacks;

	if (argc <= 2)
		return (0);
	stacks = init_stacks(argc, argv);
	check_digits(argv, argc);
	check_duplicate(argc, argv);
	check_sorted(argc, stacks);
	print_stacks(stacks,argc);
}
