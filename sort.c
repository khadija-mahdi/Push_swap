/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 07:02:39 by kmahdi            #+#    #+#             */
/*   Updated: 2023/01/31 02:20:50 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_elments(t_array *stacks, int argc)
{
	int i;
	int n1;
	int n2;
	int n3;

	i = 0;
	if (stacks->size_a == 3)
	{
		n1 = stacks->stack_a[0];
		n2 = stacks->stack_a[1];
		n3 = stacks->stack_a[2];
		if (n1 > n2 && n2 < n3 && n3 > n1)
			swap_stacks(stacks, "sa");
		else if (n1 < n2 && n2 > n3 && n3 > n1)
		{
			reverse_rorate(stacks, "rra");
			swap_stacks(stacks, "sa");
		}
		else if (n1 > n2 && n2 > n3)
		{
			swap_stacks(stacks, "sa");
			reverse_rorate(stacks, "rra");
		}
		else if (n1 < n2 && n2 > n3)
			reverse_rorate(stacks, "rra");
		else if (n1 > n2 && n2 < n3)
		{
			reverse_rorate(stacks, "rra");
			reverse_rorate(stacks, "rra");
		}
	}
}

void	sort_list(int *stack, int size)
{
	int	i;
	int	swap;

	while (size >= 0)
	{
		i = 0;
		while (i < size - 1)
		{
			if (stack[i] > stack[i + 1])
			{
				swap = stack [i];
				stack[i] = stack [i + 1];
				stack [i + 1] = swap;
			}
			i++;
		}
		size--;
	}
} 

void print_stack(t_array *stack, int i)
{
	int index = 0;
	if(i == 0)
	{
		printf("stack a  { ");
		while (index < stack->size_a)
		{
			printf("%d ,", stack->stack_a[index]);
			index++;
		}
		printf(" }\n");
		return ;	
	}
	printf("stack b{ ");
	while (index < stack->size_b)
	{
		printf("%d ,", stack->stack_b[index]);
		index++;
	}
	printf(" }\n");
	return ;
		
}

int get_positions(t_array*stacks, int *list, int start, int end)
{
	int j = 0;
	int i = start;
	while(j < stacks->size_a)
	{
		while(i < end)
		{
			if (stacks->stack_a[j] == list[i])
				return (j); 
			else
				return(-1);
			i++;
		}
		j++;
	}
}
void cpy_to_list(int size, t_array *stacks )
{
	int start;
	int end;

	int *list = malloc ((size) * sizeof(int));

	i  = 0;
	while (i < stacks->size_a)
	{
		list[i] = stacks->stack_a[i];
		i++;
	}
	sort_list(list, stacks->size_a);
	i = 0;
	printf("\nlist_after{ ");
	while (i < stacks->size_a)
	{
		printf("%d ,", list[i]);
		i++;
	}
	printf(" }\n\n");
	start = (stacks->size_a / 2) - 8;
	end = (stacks->size_a / 2) + 8;
	
	int index = get_positions(stacks, list, start, end);
	printf("index :  %d", index);
	// if (stacks->size_a > 16 && stacks->size_a < 150)
	// {
	// 	printf(" i = %d ,", i);
	// 	printf(" i = %d ,", (stacks->size_a / 2) + 8);
	// 	print_stack(stacks,0);
	// 	print_stack(stacks,1);
	// 	while (k < (stacks->size_a / 2) + 8)
	// 	{
	// 		j = 0;
	// 		while (list[i] != stacks->stack_a[j])
	// 			i++;
	// 		printf(" i  = %d\n ,", i);
	// 		if (stacks->stack_a[j] == list[i])
	// 		{
	// 			if (list[i] != stacks->stack_a[0])
	// 			{
	// 				if (j < stacks->size_a / 2 - 1)
	// 				{
	// 					reverse_rorate(stacks, "rra");
	// 					print_stack(stacks, 0);
	// 					printf("ana : %d\n", stacks->stack_a[j]);
	// 					print_stack(stacks, 0);
	// 					print_stack(stacks, 1);
	// 				}

	// 				if (j > stacks->size_a / 2 - 1)
	// 				{
	// 					rorate(stacks, "ra");
	// 					print_stack(stacks, 0);
	// 					printf("ana_in ra : %d\n", stacks->stack_a[j]);
	// 					print_stack(stacks, 0);
	// 					print_stack(stacks, 1);
	// 				}
	// 			}
	// 			push_stacks(stacks, "pb");
	// 		}
	// 		k++;
	// 	}
	// 	print_stack(stacks, 0);
	// 	print_stack(stacks, 1);
	// 	printf("\nlist{ ");
	// }
	// else
	// 	printf("bzaaaf");
}
void check_list(t_array *stacks)
{
	int i ;
	
	i  = 0;
	
	cpy_to_list(stacks->size_a,stacks);
	
}