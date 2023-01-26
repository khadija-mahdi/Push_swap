/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 04:21:55 by kmahdi            #+#    #+#             */
/*   Updated: 2023/01/26 23:44:52 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_stacks(t_array *stacks, char *inst)
{
	if (!ft_strcmp(inst, "sa"))
	{
		ft_swap(&stacks->stack_a[0], &stacks->stack_a[1]);
		ft_putstr("sa\n");
	}
	else if (!ft_strcmp(inst, "sb") && stacks->size_b != 0)
	{
		ft_swap(&stacks->stack_b[0], &stacks->stack_b[1]);
		ft_putstr("sb\n");
	}
	else if (!ft_strcmp(inst, "ss") && stacks->size_b != 0)
	{
		ft_swap(&stacks->stack_a[0], &stacks->stack_a[1]);
		ft_swap(&stacks->stack_b[0], &stacks->stack_b[1]);
		ft_putstr("ss\n");
	}
}

void	remove_top_stacks(int size, int *stack_name)
{
	int	i;

	i = 0;
	while (i < size)
	{
		stack_name[i] = stack_name[i + 1];
		i++;
	}
}

void	reverse_top_stacks(int size, int *stack_name)
{
	int	i;

	i = 0;
	while (i < size)
		i++;
	i--;
	while (i != 0)
	{
		stack_name[i] = stack_name[i - 1];
		i--;
	}
}

void	push_stacks(t_array *stacks, char *inst)
{
	if (!ft_strcmp(inst, "pa") && stacks->size_b != 0)
	{
		stacks->size_a++;
		reverse_top_stacks(stacks->size_a, stacks->stack_a);
		stacks->stack_a[0] = stacks->stack_b[0];
		remove_top_stacks(stacks->size_b, stacks->stack_b);
		stacks->size_b--;
		ft_putstr("pa\n");
	}
	else if (!ft_strcmp(inst, "pb"))
	{
		stacks->size_b++;
		reverse_top_stacks(stacks->size_b, stacks->stack_b);
		stacks->stack_b[0] = stacks->stack_a[0];
		remove_top_stacks(stacks->size_a, stacks->stack_a);
		stacks->size_a--;
		ft_putstr("pb\n");
	}
}
