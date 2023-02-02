/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:37:16 by kmahdi            #+#    #+#             */
/*   Updated: 2023/02/02 02:55:04 by kmahdi           ###   ########.fr       */
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
	int *list;
	int	size_a;
	int	size_b;
	int	list_size;
}			t_array;

void	check_opera(char **argv, int index, int j);
void	check_sorted(int argc, t_array *array);
void	check_digits(char **argv, int argc);
void	check_duplicate(int argc, char **argv);
int		ft_putstr(char *s);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(const char *s);
void	sort_list(int *stack, int size);
void	ft_swap(int *a, int *b);
int		ft_isdigit(int c);
int		count(const char *str, int sym);
int		ft_atoi(const char *str);
void	exit_msg(char *msg);
void	rotate(t_array *stacks, char *inst);
void	reverse_rotate(t_array *stacks, char *inst);
void	swap_stacks(t_array *stacks, char *inst);
void	push_stacks(t_array *stacks, char *inst);
void	sort_three_elments(t_array *stacks);
void	sort_tow_three(t_array *stacks);
void 	print_stack(t_array *stack, int i);
void	push_stack_b(t_array *stacks);
void	push_to_stack_a(t_array *stacks);
int		get_positions(t_array *stacks, int start, int end);
void	update_range(int *size_max, int *start,int *end );
void	push_to_stack_b(t_array *stacks, int *size_max,int *start, int *end);
int		get_top_b_pos(t_array *stacks,int top_b);


void	show(t_array *stack, int clear);

#endif