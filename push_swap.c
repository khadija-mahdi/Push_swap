/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:47:17 by kmahdi            #+#    #+#             */
/*   Updated: 2023/02/03 04:47:44 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_msg(char *msg)
{
	ft_putstr(msg);
	exit(1);
}

int	get_positions(t_array *stacks, int start, int end)
{
	int	j;
	int	i;

	j = 0;
	while (j < stacks->size_a)
	{
		i = start;
		while (i <= end)
		{
			if (stacks->stack_a[j] == stacks->list[i])
				return (j);
			i++;
		}
		j++;
	}
	return (-1);
}

void	update_range(int *size_max, int *start, int *end)
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
	if (*end > *size_max)
		*end = *size_max;
}

int	get_index(t_array *stacks, int top_b)
{
	int	index;

	index = 0;
	while (index < stacks->size_b)
	{
		if (stacks->stack_b[index] == stacks->list[top_b])
			return (index);
		index++;
	}
	return (-1);
}

void	val_start_end(int *size_max, int *start, int *end)
{
	if (*size_max > 16 && *size_max < 150)
	{
		(*start) = (*size_max / 2) + 8;
		(*end) = (*size_max / 2) - 8;
	}
	else if (*size_max >= 150)
	{
		(*start) = (*size_max / 2) + 16;
		(*end) = (*size_max / 2) + 16;
	}
}

