/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 03:28:30 by kmahdi            #+#    #+#             */
/*   Updated: 2023/02/04 06:18:32 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			exit_msg("Error\n");
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
	check_duplicate(stacks);
	check_sorted(argc, stacks);
	sort_tow_three(stacks);
	sort_short_elments(stacks);
	push_stack_b(stacks);
	push_to_stack_a(stacks);
}
