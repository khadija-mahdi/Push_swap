/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 03:28:30 by kmahdi            #+#    #+#             */
/*   Updated: 2023/02/03 08:20:35 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_array *stack, int i)
{
	int	index;

	index = 0;
	if (i == 0)
	{
		printf("\nstack a  { ");
		while (index < stack->size_a)
		{
			printf("%d ,", stack->stack_a[index]);
			index++;
		}
		printf(" }\n");
		return ;
	}
	else if (i == 1)
	{
		printf("\nstack b{ ");
		while (index < stack->size_b)
		{
			printf("%d ,", stack->stack_b[index]);
			index++;
		}
		printf(" }\n");
	}
	else
	{
		index = 0;
		printf("\nlist { ");
		while (index < stack->list_size)
		{
			printf("%d ,", stack->list[index]);
			index++;
		}
		printf(" }\n");
		return ;
	}
}

t_array	*init_stacks(int argc, char **argv, t_array	*array)
{
	int	i;
	int	j;

	array = malloc(sizeof(t_array));
	array->stack_b = malloc((argc - 1) * sizeof(int));
	array->stack_a = malloc((argc - 1) * sizeof(int));
	array->list = malloc((argc - 1) * sizeof(int));
	array->size_a = 0;
	array->size_b = 0;
	array->list_size = 0;
	i = 1;
	j = 0;
	while (j < argc - 1)
	{
		if (argv[i][0] == '\0')
			exit_msg("Error_empty \n");
		array->stack_a[j] = ft_atoi(argv[i]);
		array->list[j] = array->stack_a[j];
		array->size_a++;
		array->list_size++;
		j++;
		i++;
	}
	sort_list(array->list, array->list_size);
	return (array);
}

int	main(int argc, char **argv)
{
	t_array	*stacks;

	stacks = NULL;
	if (argc < 2)
		return (0);
	stacks = init_stacks(argc, argv, stacks);
	check_digits(argv, argc);
	check_duplicate(argc, argv);
	check_sorted(argc, stacks);
	sort_tow_three(stacks);
	sort_short_elments(stacks);
	push_stack_b(stacks);
	push_to_stack_a(stacks);
	// print_stack(stacks, 0);
	// print_stack(stacks, 1);
	// show(stacks, 0);
}