/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 09:00:40 by kmahdi            #+#    #+#             */
/*   Updated: 2023/02/05 00:59:06 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	exit_msg(char *msg)
{
	ft_putstr(msg);
	exit(1);
}

void	b_check_sorted(t_stack *stack)
{
	int	i;
	int	is_sorted;

	is_sorted = 1;
	i = 0;
	while (i < stack->size_a - 1)
	{
		if (stack->stack_a[i] > stack->stack_a[i + 1])
		{
			is_sorted = 0;
			break ;
		}
		i++;
	}
	if (is_sorted == 1)
	{
		ft_putstr("OK\n");
		exit(0);
	}
	else
	{
		ft_putstr("KO\n");
		exit(0);
	}
}

void	b_check_duplicate(t_stack *stacks)

{
	int	index;
	int	j;

	index = 0;
	while (index < stacks->size_a)
	{
		j = index + 1;
		while (j < stacks->size_a)
		{
			if (stacks->stack_a[index] == stacks->stack_a[j])
				exit_msg("Error\n");
			j++;
		}
		index++;
	}
}
