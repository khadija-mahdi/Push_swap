/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 04:06:36 by kmahdi            #+#    #+#             */
/*   Updated: 2023/01/25 05:33:28 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rorate_stacks(int argc, t_array *stacks, int *stack_name)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc - 1)
	{
		stacks->new_stack[j] = stack_name[i];
		i++;
		j++;
	}
	stacks->new_stack[j] = stack_name[0];
	i = 0;
	while (i < argc - 1)
	{
		stack_name[i] = stacks->new_stack[i];
		i++;
	}
}

void	rorate(int argc, t_array *stacks, char *inst)
{
	if (!ft_strcmp(inst, "ra"))
	{
		rorate_stacks(argc, stacks, stacks->stack_a);
		ft_putstr("pa\n");
	}
	if (!ft_strcmp(inst, "rb"))
	{
		rorate_stacks(argc, stacks, stacks->stack_b);
		ft_putstr("rb\n");
	}
	if (!ft_strcmp(inst, "rr"))
	{
		rorate_stacks(argc, stacks, stacks->stack_a);
		rorate_stacks(argc, stacks, stacks->stack_b);
		ft_putstr("rr\n");
	}
}

void	reverse_rorate_stacks(int argc, t_array *stacks, int *stack_name)
{
	int	j;
	int	i;

	j = 0;
	while (j < argc - 1)
		j++;
	stacks->new_stack[0] = stack_name[j - 1];
	j = 1;
	i = 0;
	while (i < argc - 1)
	{
		stacks->new_stack[j] = stack_name[i];
		j++;
		i++;
	}
	i = 0;
	while (i < argc - 1)
	{
		stack_name[i] = stacks->new_stack[i];
		i++;
	}
}

void	reverse_rorate(int argc, t_array *stacks, char *inst)
{
	if (!ft_strcmp(inst, "rra"))
	{
		reverse_rorate_stacks(argc, stacks, stacks->stack_a);
		ft_putstr("rra\n");
	}
	if (!ft_strcmp(inst, "rrb"))
	{
		reverse_rorate_stacks(argc, stacks, stacks->stack_b);
		ft_putstr("rrb\n");
	}
	if (!ft_strcmp(inst, "rrr"))
	{
		reverse_rorate_stacks(argc, stacks, stacks->stack_a);
		reverse_rorate_stacks(argc, stacks, stacks->stack_b);
		ft_putstr("rrr\n");
	}
}
