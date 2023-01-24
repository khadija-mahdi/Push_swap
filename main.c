/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 03:28:30 by kmahdi            #+#    #+#             */
/*   Updated: 2023/01/24 19:20:12 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_a(int argc, t_array *array)
{
	int i = 1;
	if(argc == 2)
		exit(0);
	while (i < argc )
	{
		printf("stack_a before swap: %d\n", array->stack_a[i]);
		i++;
	}
	printf("------------------\n");
	i = 1;
	while (i < argc)
	{
		printf("stack_a : %d\n", array->stack_a[i]);
		i++;
	}
	array->stack_b = malloc((argc - 1) * sizeof(int *));
	array->stack_b = NULL;
}

int	main(int argc, char **argv)
{
	t_array	*array;

	array = malloc(sizeof(t_array));
	if (!array)
		exit_msg("ERROR maloc !!");
	if (argc < 2)
		return (0);
	check_digits(argv, argc);
	check_duplicate(argc, argv);
	push_to_array_check_sorted(argv, argc, array);
	swap_a(argc,array);
	
}
