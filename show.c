/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:26:20 by anaimi            #+#    #+#             */
/*   Updated: 2023/02/01 21:32:35 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_int_length(long value)
{
	int	l;

	l = 1;
	if (value < 0)
	{
		value *= (-1);
		l += 1;
	}
	while (value > 9)
	{
		l++;
		value /= 10;
	}
	return (l);
}

void	show(t_array *stack, int clear)
{
	int	i;
	int	j;

	i = stack->list_size - 1;
	printf("\033[0;37m");
	printf("_________________________\n");
	while (0 <= i)
	{
		if (0 <= i && i <= stack->size_a - 1)
		{
			if (stack->stack_a[i] == stack->list[i])
				printf("|\033[0;32m");
			else if (stack->stack_a[i] != stack->list[i])
				printf("|\033[0;31m");
			printf("%d", stack->stack_a[i]);
			j = ft_int_length(stack->stack_a[i]);
			while (j < 11)
			{
				printf(" ");
				j++;
			}
		}
		else
			printf("|           ");
		printf("\033[0;37m");
		if (0 <= i && i <= stack->size_b - 1)
		{
			printf("|\033[0;33m");
			printf("%d", stack->stack_b[i]);
			j = ft_int_length(stack->stack_b[i]);
			while (j < 11)
			{
				printf(" ");
				j++;
			}
			printf("\033[0;37m|\n");
		}
		else
			printf("|           |\n");
		i--;
	}
	printf("|-----------------------|\n");
	printf("|a          |b          |\n");
	printf("|-----------------------|\n");
	usleep(100000);
	if (clear)
	{
		// getchar();
		system("clear");
	}
}
