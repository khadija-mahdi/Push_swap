/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 07:02:39 by kmahdi            #+#    #+#             */
/*   Updated: 2023/01/27 00:12:08 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_elments(t_array *stacks, int argc)
{
	int	n1;
	int	n2;
	int	n3;

	if (argc == 4)
	{
		n1 = stacks->stack_a[0];
		n2 = stacks->stack_a[1];
		n3 = stacks->stack_a[2];
		if (n1 > n2 && n2 < n3 && n3 > n1)
			swap_stacks(stacks, "sa");
		else if (n1 < n2 && n2 > n3 && n3 > n1)
		{
			reverse_rorate(argc, stacks, "rra");
			swap_stacks(stacks, "sa");
		}
		else if (n1 > n2 && n2 > n3)
		{
			swap_stacks(stacks, "sa");
			reverse_rorate(argc, stacks, "rra");
		}
		else if (n1 < n2 && n2 > n3)
			reverse_rorate(argc, stacks, "rra");
		else if (n1 > n2 && n2 < n3)
		{
			reverse_rorate(argc, stacks, "rra");
			reverse_rorate(argc, stacks, "rra");
		}
	}
}
