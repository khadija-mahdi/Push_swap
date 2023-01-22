/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 03:28:30 by kmahdi            #+#    #+#             */
/*   Updated: 2023/01/22 15:10:49 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	stack_a[argc - 1];

	// stack_b = NULL;
	if (argc == 1)
		return (0);
	check_duplicate(argc, argv);
	check_digits(argv, argc);
	push_to_array(argv, argc, stack_a);
}
