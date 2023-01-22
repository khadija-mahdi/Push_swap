/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:37:16 by kmahdi            #+#    #+#             */
/*   Updated: 2023/01/21 21:52:26 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
#include    <stdio.h>
#include <string.h>

int		ft_putstr(char *s);
int		ft_strlen(const char *s);
void	ft_sort_int_tab(int *tab, int size);
void	ft_swap(int *a, int *b);
char	*ft_itoa(int n);
int		get_nub_len(long n);
int		ft_isdigit(int c);
int		count(const char *str, int sym);
int		ft_atoi(const char *str);
int     ft_strcmp(const char *s1, const char *s2);

#endif