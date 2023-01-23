/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:37:16 by kmahdi            #+#    #+#             */
/*   Updated: 2023/01/23 20:15:12 by kmahdi           ###   ########.fr       */
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
}			t_array;

void	check_opera(char **argv, int index, int j);
void	push_to_array_check_sorted(char **argv, int argc, t_array *array);
void	check_digits(char **argv, int argc);
void	check_duplicate(int argc, char **argv);
int		ft_putstr(char *s);
int		ft_strlen(const char *s);
void	ft_sort_int_tab(int *tab, int size);
void	ft_swap(int *a, int *b);
int		ft_isdigit(int c);
int		count(const char *str, int sym);
int		ft_atoi(const char *str);
void	exit_msg(char *msg);
int		ft_strcmp(char *s1, char *s2);

#endif