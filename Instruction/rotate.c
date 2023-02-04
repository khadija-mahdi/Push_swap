/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 04:06:36 by kmahdi            #+#    #+#             */
/*   Updated: 2023/02/03 23:49:54 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*rotate_stacks(int *stack, int *size)
{
	int	i;
	int	j;
	int	*new_stack;

	if (*size <= 1)
		return (stack);
	new_stack = malloc((*size) * sizeof(int));
	i = 1;
	j = 0;
	while (i < (*size))
	{
		new_stack[j] = stack[i];
		i++;
		j++;
	}
	new_stack[j] = stack[0];
	free(stack);
	return (new_stack);
}

void	rotate(t_array *stacks, char *inst)
{
	if (!ft_strcmp(inst, "ra"))
	{
		stacks->stack_a = rotate_stacks(stacks->stack_a, &stacks->size_a);
		ft_putstr("ra\n");
	}
	else if (!ft_strcmp(inst, "rb") && stacks->size_b != 0)
	{
		stacks->stack_b = rotate_stacks(stacks->stack_b, &stacks->size_b);
		ft_putstr("rb\n");
	}
	else if (!ft_strcmp(inst, "rr") && stacks->size_b != 0)
	{
		stacks->stack_a = rotate_stacks(stacks->stack_a, &stacks->size_a);
		stacks->stack_b = rotate_stacks(stacks->stack_b, &stacks->size_b);
		ft_putstr("rr\n");
	}
}

int	*reverse_rotate_stack(int *stack, int *size)
{
	int	i;
	int	j;
	int	*new_stack;

	if (*size <= 1)
		return (stack);
	new_stack = malloc((*size) * sizeof(int));
	new_stack[0] = stack[*size - 1];
	i = 0;
	j = 1;
	while (i < (*size - 1))
	{
		new_stack[j] = stack[i];
		i++;
		j++;
	}
	free(stack);
	return (new_stack);
}

void	reverse_rotate(t_array *stacks, char *inst)
{
	if (!ft_strcmp(inst, "rra"))
	{
		stacks->stack_a = reverse_rotate_stack(stacks->stack_a,
				&stacks->size_a);
		ft_putstr("rra\n");
	}
	else if (!ft_strcmp(inst, "rrb") && stacks->size_b != 0)
	{
		stacks->stack_b = reverse_rotate_stack(stacks->stack_b,
				&stacks->size_b);
		ft_putstr("rrb\n");
	}
	else if (!ft_strcmp(inst, "rrr") && stacks->size_b != 0)
	{
		stacks->stack_a = reverse_rotate_stack(stacks->stack_a,
				&stacks->size_a);
		stacks->stack_b = reverse_rotate_stack(stacks->stack_b,
				&stacks->size_b);
		ft_putstr("rrr\n");
	}
}
