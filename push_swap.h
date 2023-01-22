/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:37:16 by kmahdi            #+#    #+#             */
/*   Updated: 2023/01/22 15:11:23 by kmahdi           ###   ########.fr       */
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

void	check_opera(char **argv, int index, int j);
void	push_to_array(char **argv, int argc, int stack_a[argc - 1]);
void	check_digits(char **argv, int argc);
void	check_duplicate(int argc, char **argv);
int		ft_putstr(char *s);
int		ft_strlen(const char *s);
void	ft_sort_int_tab(int *tab, int size);
void	ft_swap(int *a, int *b);
int		ft_isdigit(int c);
int		count(const char *str, int sym);
int		ft_atoi(const char *str);
int		ft_strcmp(const char *s1, const char *s2);

#endif