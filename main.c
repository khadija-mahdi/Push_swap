/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 03:28:30 by kmahdi            #+#    #+#             */
/*   Updated: 2023/01/22 12:59:01 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void check_opera(char **argv, int index, int j)
{
	if (argv[index][j] == '-' || argv[index][j] == '+')
	{
		if (argv[index][j + 1] == ' ')
		{
			ft_putstr("Error2 : \n");
			exit(1);
		}
		if (ft_strlen(argv[index]) == 1)
		{
			ft_putstr("Error : one opera : \n");
			exit(1);
		}
	}
}

void	check_digits(char **argv,int argc)
{
	int num;
	int index;
	int j;
	
	index = 1;
	while (index < argc)
	{
		j = 0;
		while (argv[index][j])
		{
			check_opera(argv,index,j);
			if (!ft_isdigit(argv[index][j]))
			{
				ft_putstr("Error: not digit\n");
				exit(1);
			}
			j++;
		}
		num = ft_atoi(argv[index]);
		index++;
    }
}

void	check_duplicate(int argc, char **argv)
{
    int index;
	int	j;
	
	index = 1;
    while ( index < argc )
	{
		j = index + 1;
        while ( j < argc) 
		{
            if (ft_strcmp(argv[index], argv[j]) == 0) 
			{
                ft_putstr("Error : dupli\n");
				exit(1);
            }
			j++;
        }
		index++;
	}
}

// void check_s(int argc, char **argv)
// {
// }
int main(int argc, char **argv)
{
	// stack_b = NULL;
	if(argc == 1)
		return(0);
		check_duplicate(argc,argv);
		check_digits(argv,argc);
    return 0;
}
