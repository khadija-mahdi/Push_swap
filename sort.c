/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 07:02:39 by kmahdi            #+#    #+#             */
/*   Updated: 2023/02/02 04:20:01 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three_elments(t_array *stacks)
{
	int n1;
	int n2;
	int n3;

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

void sort_tow_three(t_array *stacks)
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
		else
			sort_three_elments(stacks);
	}
	if (stacks->size_a == 2)
		swap_stacks(stacks, "sa");
}

void update_range(int *size_max, int *start, int *end)
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

void push_to_stack_b(t_array *stacks, int *size_max, int *start, int *end)
{
	int index;

	index = get_positions(stacks, *start, *end);
	while ((stacks->list[*start] > stacks->stack_a[0] || stacks->list[*end] < stacks->stack_a[0]) && index > stacks->size_a / 2 - 1)
		reverse_rotate(stacks, "rra");
	while ((stacks->list[*start] > stacks->stack_a[0] || stacks->list[*end] < stacks->stack_a[0]) && index <= stacks->size_a / 2 - 1)
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

int get_top_b_pos(t_array *stacks, int top_b)
{
	int index;

	index = 0;
	while (stacks->stack_b[index] != stacks->list[top_b])
		index++;
	return (index);
}

int get_index(t_array *stacks, int top_b)
{
	int index = 0;
	while(index < stacks->size_b)
	{
		if (stacks->stack_b[index] == stacks->list[top_b])
			return (index);
		index++;
	}
	return(-1);
} 


void push_to_stack_a(t_array *stacks)
{
	int down;
	int top_b;
	int limter = 0;

	down = 0;
	top_b = stacks->list_size - 1;
	int index = 0;

	if (stacks->size_b > 16)
	{
		while (stacks->size_b > 0)
		{
			index = get_index(stacks, top_b);
			// printf("looking for %d and index is %d \n", stacks->list[top_b], index);
			if (index == -1)
			{
				reverse_rotate(stacks, "rra");
				down--;
				top_b--;
			}
			else
			{
				if (stacks->list[top_b] == stacks->stack_b[0])
				{
					push_stacks(stacks, "pa");
					top_b--;
				}
				else
				{
					if (down == 0 || stacks->stack_b[0] > stacks->stack_a[stacks->size_a - 1])
					{
						push_stacks(stacks, "pa");
						rotate(stacks, "ra");
						down++;
					}
					else
					{
						if (index > stacks->size_b / 2 - 1)
							reverse_rotate(stacks, "rrb");
						if (index < stacks->size_b / 2 - 1)
							rotate(stacks, "rb");
					}
				}
			}
			limter++;
		}
		while (down > 0)
		{
			reverse_rotate(stacks, "rra");
			down--;
		}
	}
}