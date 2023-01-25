/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 04:21:55 by kmahdi            #+#    #+#             */
/*   Updated: 2023/01/25 06:35:13 by kmahdi           ###   ########.fr       */
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
	if (stacks->stack_b != NULL)
	{
		if (!ft_strcmp(inst, "sb"))
		{
			ft_swap(&stacks->stack_b[0], &stacks->stack_b[1]);
			ft_putstr("sb\n");
		}
		if (!ft_strcmp(inst, "ss"))
		{
			ft_swap(&stacks->stack_a[0], &stacks->stack_a[1]);
			ft_swap(&stacks->stack_b[0], &stacks->stack_b[1]);
			ft_putstr("ss\n");
		}
	}
	else
		exit(0);
}

void	remove_top_stacks(int argc, int *stack_name)
{
	int	i;

	i = 0;
	while (i < argc - 2)
	{
		stack_name[i] = stack_name[i + 1];
		i++;
	}
}

void	push_stacks(int argc, t_array *stacks, char *inst)
{
	if (!ft_strcmp(inst, "pa"))
	{
		is_empty(argc, stacks->stack_b);
		stacks->stack_a[0] = stacks->stack_b[0];
		remove_top_stacks(argc, stacks->stack_b);
		ft_putstr("pa\n");
	}
	if (!ft_strcmp(inst, "pb"))
	{
		is_empty(argc, stacks->stack_a);
		stacks->stack_b[0] = stacks->stack_a[0];
		remove_top_stacks(argc, stacks->stack_a);
		ft_putstr("pb\n");
	}
}
