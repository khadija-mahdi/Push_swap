/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 03:28:30 by kmahdi            #+#    #+#             */
/*   Updated: 2023/01/23 07:37:37 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_array *s_array;
 
	s_array = malloc(argc * sizeof(t_array));
	// if (!stack_a)
	// 	exit_msg("ERROR maloc !!");
	if (argc < 2)
		return (0);
	push_to_array(argv, argc, s_array);
	check_digits(argv, argc);
	check_duplicate(argc, argv);
}
