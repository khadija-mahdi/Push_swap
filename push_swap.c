/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:47:17 by kmahdi            #+#    #+#             */
/*   Updated: 2023/02/01 04:40:35 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_msg(char *msg)
{
	ft_putstr(msg);
	exit(1);
}

int get_positions(t_array *stacks, int start, int end)
{
	int j = 0;
	while(j < stacks->size_a)
	{
		int i = start;
		while(i <= end)
		{
			if (stacks->stack_a[j] == stacks->list[i])
				return (j);
			i++;
		}
		j++;
	}
	return(-1);
}
