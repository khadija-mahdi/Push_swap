/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 01:42:40 by kmahdi            #+#    #+#             */
/*   Updated: 2023/02/04 08:35:10 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	exit_msg(char *msg)
{
	ft_putstr(msg);
	exit(1);
}

void	check_sorted(t_stack *stack)
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
			ft_putstr("KO\n");
			break ;
		}
		i++;
	}
	if (is_sorted == 1)
		ft_putstr("OK\n");
}

t_stack	*init_stack_a(int argc, char **argv, t_stack *stacks)
{
	int i;
	int j;

	stacks = malloc(sizeof(t_stack));
	stacks->stack_a = malloc((argc - 1) * sizeof(int));
	stacks->stack_b = malloc((argc - 1) * sizeof(int));
	i = 1;
	j = 0;
	stacks->size_a = 0;
	stacks->size_a = 0;
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

void	cheker(t_stack *stacks , char **inst)
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
		b_rotate(stacks, "ra");
	else if (*inst && !ft_strcmp(*inst, "rra\n"))
		b_reverse_rotate(stacks, "rra");
	else if (*inst && !ft_strcmp(*inst, "rrb\n"))
		b_reverse_rotate(stacks, "rrb");
	else if (*inst && !ft_strcmp(*inst, "rrr\n"))
		b_reverse_rotate(stacks, "rrr");
}

int is_instruction(char **inst)
{
	if (!ft_strcmp(*inst, "sa\n"))
		return (1);
	if (!ft_strcmp(*inst, "sb\n"))
		return (1);
	if (!ft_strcmp(*inst, "ss\n"))
		return (1);
	if (!ft_strcmp(*inst, "pa\n"))
		return (1);
	if (!ft_strcmp(*inst, "pb\n"))
		return (1);
	if (!ft_strcmp(*inst, "ra\n"))
		return (1);
	if (!ft_strcmp(*inst, "rb\n"))
		return (1);
	if (!ft_strcmp(*inst, "rr\n"))
		return (1);
	if (!ft_strcmp(*inst, "rra\n"))
		return (1);
	if (!ft_strcmp(*inst, "rrb\n"))
		return (1);
	if (!ft_strcmp(*inst, "rrr\n"))
		return (1);
	else
		return (0);
}

int main(int argc, char **argv)
{
	t_stack *stacks;
	char *inst;
	int isnt_inst;

	stacks = NULL;
	isnt_inst = 0;
	
	if (argc < 2)
		return (0);
	stacks = init_stack_a(argc, argv, stacks);
	int i = 0;
	while (i < stacks->size_a - 1)
	{
		inst = get_next_line(0);
		if (inst != NULL)
		{
			if (inst && !ft_strcmp(inst, "sa\n"))
			b_swap_stacks(stacks, "sa");
			if(!(is_instruction(&inst)))
				isnt_inst++;
			else
			cheker(stacks, &inst);
		}
		else
		{
			if (isnt_inst != 0)
				exit_msg("Error\n");
			check_sorted(stacks);
			exit(0);
		}
}
}