/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 03:28:30 by kmahdi            #+#    #+#             */
/*   Updated: 2023/01/22 21:32:36 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*stack_a;

	stack_a = malloc(argc * sizeof(int));
	if (!stack_a)
	{
		printf("malloc error");
		return (0);
	}
	// stack_b = NULL;
	if (argc < 2)
		return (0);
	push_to_array(argv, argc, stack_a);
	check_digits(argv, argc);
	check_duplicate(argc, argv);
	
}
