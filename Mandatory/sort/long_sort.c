/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 06:44:53 by kmahdi            #+#    #+#             */
/*   Updated: 2023/02/04 00:05:37 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_to_stack_b(t_array *stacks, int *size_max, int *start, int *end)
{
	while ((stacks->list[*start] > stacks->stack_a[0] || stacks->list[*end]
			< stacks->stack_a[0]))
		rotate(stacks, "ra");
	push_stacks(stacks, "pb");
	if (stacks->stack_b[0] < stacks->list[*size_max / 2])
		rotate(stacks, "rb");
}

void	push_stack_b(t_array *stacks)
{
	int	start;
	int	end;
	int	size_max;
	int	index;

	size_max = stacks->size_a - 1;
	start = (size_max / 2) - 16;
	end = (size_max / 2) + 16;
	if (size_max > 16)
	{
		while (stacks->size_a > 0)
		{
			index = get_positions(stacks, start, end);
			if (index == -1)
				update_range(&size_max, &start, &end);
			else
				push_to_stack_b(stacks, &size_max, &start, &end);
		}
	}
}

void	check_push_a(t_array *stacks, int *top_b, int *down, int *index)
{
	if (stacks->list[*top_b] == stacks->stack_b[0])
	{
		push_stacks(stacks, "pa");
		(*top_b)--;
	}
	else
	{
		if (*down == 0 || stacks->stack_b[0]
			> stacks->stack_a[stacks->size_a - 1])
		{
			push_stacks(stacks, "pa");
			rotate(stacks, "ra");
			(*down)++;
		}
		else
		{
			if (*index >= stacks->size_b / 2 - 1)
				reverse_rotate(stacks, "rrb");
			if (*index < stacks->size_b / 2 - 1)
				rotate(stacks, "rb");
		}
	}
}

void	push_sorted_a(t_array *stacks, int *top_b, int *down, int *index)
{
	if (*index == -1)
	{
		reverse_rotate(stacks, "rra");
		(*down)--;
		(*top_b)--;
	}
	else
		check_push_a(stacks, top_b, down, index);
}

void	push_to_stack_a(t_array *stacks)
{
	int	down;
	int	top_b;
	int	index;

	down = 0;
	top_b = stacks->list_size - 1;
	index = 0;
	if (stacks->list_size > 16)
	{
		while (stacks->size_b > 0)
		{
			index = get_index(stacks, top_b);
			push_sorted_a(stacks, &top_b, &down, &index);
		}
		while (down > 0)
		{
			reverse_rotate(stacks, "rra");
			down--;
		}
	}
}
