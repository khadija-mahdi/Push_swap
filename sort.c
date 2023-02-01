/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 07:02:39 by kmahdi            #+#    #+#             */
/*   Updated: 2023/02/01 19:59:05 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three_elments(t_array *stacks, int argc)
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
			reverse_rotate(stacks, "rra");
			swap_stacks(stacks, "sa");
		}
		else if (n1 > n2 && n2 > n3)
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
}

void update_range(int *size_max, int *start,int *end )
{
	if (*size_max > 16 && *size_max < 150)
	{
		*start -= 8;
		*end += 8;
	}
	else if (*size_max >= 150)
	{
		*start -= 16;
		*end += 16;
	}
	if (*start <= 0)
		*start = 0;
	if (*end > *size_max - 1)
		*end = *size_max - 1;
}

void	push_to_stack_b(t_array *stacks, int *size_max,int *start, int *end)
{
	int	index;

	index = get_positions(stacks, *start, *end);
	while ((stacks->list[*start] > stacks->stack_a[0] || stacks->list[*end]
			< stacks->stack_a[0]) && index > stacks->size_a / 2 - 1)
		reverse_rotate(stacks, "rra");
	while ((stacks->list[*start] > stacks->stack_a[0] || stacks->list[*end]
			< stacks->stack_a[0]) && index <= stacks->size_a / 2 - 1)
		rotate(stacks, "ra");
	push_stacks(stacks, "pb");
	if (stacks->stack_b[0] < stacks->list[*size_max / 2 - 1])
		rotate(stacks, "rb");
}

void push_stack_b(t_array *stacks)
{
	int start;
	int end;
	int size_max;
	int index;

	size_max = stacks->size_a;
	start = (size_max / 2) - 8;
	end = (size_max / 2) + 8;
	while (stacks->size_a > 0)
	{
		index = get_positions(stacks, start, end);
		if (index == -1)
			update_range(&size_max, &start, &end);
		else
			push_to_stack_b(stacks, &size_max, &start, &end);
	}
}

// void push_to_stack_a(t_array *stacks)
// {
// 	int down;
// 	int i;
// 	int count;

// 	down = 0;
// 	i = 0;
// 	count = stacks->list_size - 1;
// 	push_stack_b(stacks);
	// while (stacks->size_b > 0)
	// {
		// while (stacks->list[count] == stacks->stack_b[0])
		// {
		// 	push_stacks(stacks, "pa");
		// 	reverse_rotate(stacks, "rra");
		// 	down++;
		// }
	// 	while(stacks->list[count] != stacks->stack_b[0])
	// 	{
	// 		if (down == 0)
	// 		{
	// 			push_stacks(stacks, "pa");
	// 			down++;
	// 		}
	// 		else
	// 		{
	// 			if (stacks->stack_a[down] < stacks->stack_b[i])
	// 			{
	// 				push_stacks(stacks, "pa");
	// 				reverse_rotate(stacks, "rra");
	// 				down++;
	// 			}
	// 		}
	// 	}
	// 	count--;
	// 	printf("%d",stacks->list[stacks->list_size - 1]);
// 	}

