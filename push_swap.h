/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:37:16 by kmahdi            #+#    #+#             */
/*   Updated: 2023/01/29 23:21:05 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <string.h>

typedef struct s_array
{
	int	*stack_a;
	int	*stack_b;
	int	*new_stack;
	int	size_a;
	int	size_b;
}			t_array;

void	check_opera(char **argv, int index, int j);
void	check_sorted(int argc, t_array *array);
void	check_digits(char **argv, int argc);
void	check_duplicate(int argc, char **argv);
int		ft_putstr(char *s);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(const char *s);
void	ft_sort_int_tab(int *tab, int size);
void	ft_swap(int *a, int *b);
int		ft_isdigit(int c);
int		count(const char *str, int sym);
int		ft_atoi(const char *str);
void	exit_msg(char *msg);
void	remove_top_stacks(int size, int *stack_name);
void	reverse_top_stacks(int size, int *stack_name);
void	rorate(t_array *stacks, char *inst);
void	reverse_rorate_stacks(t_array *stacks, int *stack_name);
void	reverse_rorate(t_array *stacks, char *inst);
void	swap_stacks(t_array *stacks, char *inst);
void	push_stacks(t_array *stacks, char *inst);
void	remove_top_stacks(int argc, int *stack_name);
void	sort_five_elments(t_array *stacks, int argc);
void	sort_three_elments(t_array *stacks,int argc);
void	sort(t_array *stacks);
void check_list(t_array *stacks);
void print_stack(t_array *stack, int i);

#endif