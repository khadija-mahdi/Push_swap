/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 07:02:39 by kmahdi            #+#    #+#             */
/*   Updated: 2023/02/03 06:57:42 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three_elments(t_array *stacks)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = stacks->stack_a[0];
	n2 = stacks->stack_a[1];
	n3 = stacks->stack_a[2];
	if (n1 > n2 && n2 > n3)
	{
		swap_stacks(stacks, "sa");
		reverse_rotate(stacks, "rra");
	}
	else if (n1 < n2 && n2 > n3)
		reverse_rotate(stacks, "rra");
	else if (n1 > n2 && n2 < n3)
	{
		reverse_rotate(stacks, "rra");
		reverse_rotate(stacks, "rra");
	}
}

void	sort_tow_three(t_array *stacks)
{
	int	i;
	int	n1;
	int	n2;
	int	n3;

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
			reverse_rotate(stacks, "rra");
			swap_stacks(stacks, "sa");
		}
		else
			sort_three_elments(stacks);
	}
	else if (stacks->size_a == 2)
	{
		printf("hi\n");
		swap_stacks(stacks, "sa");
	}
}

int	get_index_a(t_array *stacks, int min_a)
{
	int	index;

	index = 0;
	while (index < stacks->size_a)
	{
		if (stacks->stack_a[index] == stacks->list[min_a])
			return (index);
		index++;
	}
	return (-1);
}

void	sort_short_elments(t_array *stacks)
{
	int	min_a;
	int	index_a;

	min_a = 0;
	index_a = 0;
	int limter = 0;
	if (stacks->list_size > 3 && stacks->list_size <= 16)
	{
		while (stacks->size_a > 3)
		{
			index_a = get_index_a(stacks, min_a);
			while(stacks->list[min_a] != stacks->stack_a[0])
			{
				if (index_a > stacks->list_size / 2 - 1)
					reverse_rotate(stacks, "rra");
				else if (index_a <= stacks->list_size / 2 - 1)
					rotate(stacks, "ra");
			}
			push_stacks(stacks, "pb");
			min_a++;
		}
		sort_tow_three(stacks);
		while (stacks->size_b > 0)
			push_stacks(stacks, "pa");
	}
}
