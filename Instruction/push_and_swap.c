/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 04:21:55 by kmahdi            #+#    #+#             */
/*   Updated: 2023/01/28 00:45:50 by kmahdi           ###   ########.fr       */
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

int *add_to_stack(int *stack, int *size, int new_val)
{
    int i = 0;

    int *new_stack = malloc((*size + 1) * sizeof(int));
    new_stack[0] = new_val;
    while (i < (*size + 1))
    {
        new_stack[i + 1] = stack[i];
        i++;
    }
    free(stack);
    (*size)++;
    return (new_stack);
}

int *eject_f_stack(int *stack, int *size)
{
    int i = 0;
    if(*size <= 0)
        return (stack);
    int *new_stack = malloc((*size - 1) * sizeof(int));
    while (i < (*size - 1))
    {
        new_stack[i] = (stack[i + 1]);
        i++;
    }
    free(stack);
    (*size)--;
    return (new_stack);
}

void	push_stacks(t_array *stacks, char *inst)
{
	if (!ft_strcmp(inst, "pa") && stacks->size_b != 0)
	{
		stacks->stack_a = add_to_stack(stacks->stack_a, &stacks->size_a, stacks->stack_b[0]);
		stacks->stack_b = eject_f_stack(stacks->stack_b, &stacks->size_b) ;
		ft_putstr("pa\n");
	}
	else if (!ft_strcmp(inst, "pb") && (stacks->size_a != 0))
	{
		stacks->stack_b = add_to_stack(stacks->stack_b, &stacks->size_b,stacks->stack_a[0]);
		stacks->stack_a = eject_f_stack(stacks->stack_a, &stacks->size_a) ;
		ft_putstr("pb\n");
	}
}
