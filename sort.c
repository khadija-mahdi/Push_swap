/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 07:02:39 by kmahdi            #+#    #+#             */
/*   Updated: 2023/01/28 00:56:34 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_elments(t_array *stacks, int argc)
{
	int i;
	int n1;
	int n2;
	int n3;

	i = 0;
	if (stacks->size_a == 3)
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

void	sort_five_elments(t_array *stacks, int argc)
{
	int i;

	i = 0;
	if (argc == 6)
	{
		push_stacks(stacks, "pb");
		push_stacks(stacks, "pb");
		if (stacks->size_a == 3)
			sort_three_elments(stacks, argc);
		// if (stacks->stack_b[0] > stacks->stack_b[1])
		// 	swap_stacks(stacks, "sa");
		// push_stacks(stacks, "pa");
		// push_stacks(stacks, "pa");
		// reverse_rorate(argc, stacks, "rra");
		// reverse_rorate(argc, stacks, "rra");
		

	}
}

