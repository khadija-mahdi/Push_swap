/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 03:14:21 by kmahdi            #+#    #+#             */
/*   Updated: 2023/02/04 09:36:19 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 434
# endif

typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	*list;
	int	size_a;
	int	size_b;
}		t_stack;

int		ft_isdigit(int c);
int		count(const char *str, int sym);
int		ft_atoi(const char *str);
void	exit_msg(char *msg);
int		ft_putstr(char *s);
int		ft_strlen(const char *s);
void	ft_swap(int *a, int *b);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	sort_list(int *stack, int size);
void	b_rotate(t_stack *stacks, char *inst);
void	b_reverse_rotate(t_stack *stacks, char *inst);
void	b_swap_stacks(t_stack *stacks, char *inst);
void	b_push_stacks(t_stack *stacks, char *inst);
int		ft_strcmp(char *s1, char *s2);
void	check_opera(char **argv, int index, int j);
void	check_digits(char **argv, int argc);
void	b_check_duplicate(t_stack *stacks);
void	b_check_sorted(t_stack *stack);

#endif