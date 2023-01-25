/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:47:17 by kmahdi            #+#    #+#             */
/*   Updated: 2023/01/25 06:32:26 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_msg(char *msg)
{
	ft_putstr(msg);
	exit(1);
}

void	is_empty(int argc, int *stack_name)
{
	int	i;
	int	is_empty;

	is_empty = 1;
	i = 0;
	while (i < argc - 1)
	{
		if (stack_name[i] != 0)
		{
			is_empty = 0;
			break ;
		}
		i++;
	}
	if (is_empty == 1)
		exit_msg("empty \n");
}
