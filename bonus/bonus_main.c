/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 01:42:40 by kmahdi            #+#    #+#             */
/*   Updated: 2023/02/05 01:03:23 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*init_stack_a(int argc, char **argv, t_stack *stacks)
{
	int	i;
	int	j;

	stacks = malloc(sizeof(t_stack));
	stacks->stack_a = malloc((argc - 1) * sizeof(int));
	stacks->stack_b = malloc((argc - 1) * sizeof(int));
	i = 1;
	j = 0;
	stacks->size_a = 0;
	stacks->size_b = 0;
	while (j < argc - 1)
	{
		if (argv[i][0] == '\0')
			exit_msg("Error\n");
		stacks->stack_a[j] = ft_atoi(argv[i]);
		stacks->size_a++;
		j++;
		i++;
	}
	return (stacks);
}

void	cheker(t_stack *stacks, char **inst)
{
	if (*inst && !ft_strcmp(*inst, "sb\n"))
		b_swap_stacks(stacks, "sb");
	else if (*inst && !ft_strcmp(*inst, "ss\n"))
		b_swap_stacks(stacks, "ss");
	else if (*inst && !ft_strcmp(*inst, "pa\n"))
		b_push_stacks(stacks, "pa");
	else if (*inst && !ft_strcmp(*inst, "pb\n"))
		b_push_stacks(stacks, "pb");
	else if (*inst && !ft_strcmp(*inst, "ra\n"))
		b_rotate(stacks, "ra");
	else if (*inst && !ft_strcmp(*inst, "rb\n"))
		b_rotate(stacks, "rb");
	else if (*inst && !ft_strcmp(*inst, "rra\n"))
		b_reverse_rotate(stacks, "rra");
	else if (*inst && !ft_strcmp(*inst, "rrb\n"))
		b_reverse_rotate(stacks, "rrb");
	else if (*inst && !ft_strcmp(*inst, "rrr\n"))
		b_reverse_rotate(stacks, "rrr");
	else
	{
		ft_putstr("Error\n");
		exit(0);
	}
}

void	check_elemntes(t_stack *stacks)
{
	int		i;
	char	*inst;

	i = 0;
	while (1)
	{
		inst = get_next_line(0);
		if (inst != NULL)
		{
			if (inst && !ft_strcmp(inst, "sa\n"))
				b_swap_stacks(stacks, "sa");
			else
				cheker(stacks, &inst);
		}
		if (inst == NULL)
			break ;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stacks;

	stacks = NULL;
	if (argc < 2)
		return (0);
	stacks = init_stack_a(argc, argv, stacks);
	check_digits(argv, argc);
	b_check_duplicate(stacks);
	check_elemntes(stacks);
	b_check_sorted(stacks);
}
