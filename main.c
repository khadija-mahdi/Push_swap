/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 03:28:30 by kmahdi            #+#    #+#             */
/*   Updated: 2023/01/28 00:42:52 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_array *stacks)
{
	int	j;

	printf("-------------------------------\n");
	j = 0;
	while (j < stacks->size_b)
	{
		printf("stack_b  ---->: %d\n", stacks->stack_b[j]);
		j++;
	}
	printf("-------------------------------\n");
	j = 0;
	while ( j < stacks->size_a)
	{
		printf("stack_a  ---->: %d\n", stacks->stack_a[j]);
		j++;
	}
	printf("-------------------------------\n");
	printf("size_b----> %d\n", stacks->size_b);
	printf("size_a----> %d\n", stacks->size_a);
	printf("-------------------------------\n");
}

t_array	*init_stacks(int argc, char **argv)
{
	t_array	*array;
	int		i;
	int		j;

	array = malloc(sizeof(t_array));
	if (!array)
		exit_msg("ERROR maloc !!");
	array->stack_b = malloc((argc) * sizeof(int));
	array->new_stack = malloc((argc - 1) * sizeof(int));
	array->stack_a = malloc(argc * sizeof(int));
	array->size_a = 0;
	array->size_b = 0;
	i = 1;
	j = 0;
	while (j < argc - 1)
	{
		if (argv[i][0] == '\0')
			exit_msg("Error_empty \n");
		array->stack_a[j] = ft_atoi(argv[i]);
		array->size_a++;
		i++;
		j++;
	}
	return (array);
}

int	main(int argc, char **argv)
{
	t_array	*stacks;

	if (argc < 2)
		return (0);
	stacks = init_stacks(argc, argv);
	check_digits(argv, argc);
	check_duplicate(argc, argv);
	check_sorted(argc, stacks);
	print_stacks(stacks);
	
	sort_five_elments(stacks, argc);
	// sort_three_elments(stacks, argc);

	print_stacks(stacks);
}
