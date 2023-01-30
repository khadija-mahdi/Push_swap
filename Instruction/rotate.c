/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 04:06:36 by kmahdi            #+#    #+#             */
/*   Updated: 2023/01/29 21:58:14 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int *rorate_stacks(int *stack, int *size)
{
	int	i;
	int	j;

	int *new_stack = malloc((*size) * sizeof(int));
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

void	rorate(t_array *stacks, char *inst)
{
	if (!ft_strcmp(inst, "ra"))
	{
		stacks->stack_a = rorate_stacks(stacks->stack_a, &stacks->size_a);
		ft_putstr("ra\n");
	}
	else if (!ft_strcmp(inst, "rb") && stacks->size_b != 0)
	{
		stacks->stack_b = rorate_stacks(stacks->stack_b, &stacks->size_b);
		ft_putstr("rb\n");
	}
	else if (!ft_strcmp(inst, "rr") && stacks->size_b != 0)
	{
		stacks->stack_a = rorate_stacks(stacks->stack_a, &stacks->size_a);
		stacks->stack_b = rorate_stacks(stacks->stack_b, &stacks->size_b);
		ft_putstr("rr\n");
	}
}


int *add_to_stack_rotate(int *stack, int *size)
{

	int j;
    int *new_stack = malloc((*size) * sizeof(int));
	
	new_stack[0] = stack[*size - 1];
	
	int i = 0;
	j = 1;
    while (i < (*size) - 1)
    {
        new_stack[j] = stack[i];
        i++;
		j++;
    }
    free(stack);
    return (new_stack);
}

void	reverse_rorate(t_array *stacks, char *inst)
{
	if (!ft_strcmp(inst, "rra"))
	{
		stacks->stack_a = add_to_stack_rotate(stacks->stack_a,&stacks->size_a);
		ft_putstr("rra\n");
	}
	else if (!ft_strcmp(inst, "rrb") && stacks->size_b != 0)
	{
		stacks->stack_b = add_to_stack_rotate(stacks->stack_b,&stacks->size_b);
		ft_putstr("rrb\n");
	}
	else if (!ft_strcmp(inst, "rrr") && stacks->size_b != 0)
	{
		stacks->stack_a = add_to_stack_rotate(stacks->stack_a,&stacks->size_a);
		stacks->stack_b = add_to_stack_rotate(stacks->stack_b,&stacks->size_b);
		ft_putstr("rrr\n");
	}
}
