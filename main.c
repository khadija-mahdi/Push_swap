/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 03:28:30 by kmahdi            #+#    #+#             */
/*   Updated: 2023/01/23 20:15:55 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_array	*array;

	array = malloc((argc - 1) * sizeof(t_array));
	if (!array)
		exit_msg("ERROR maloc !!");
	if (argc < 2)
		return (0);
	check_digits(argv, argc);
	check_duplicate(argc, argv);
	push_to_array_check_sorted(argv, argc, array);
}
