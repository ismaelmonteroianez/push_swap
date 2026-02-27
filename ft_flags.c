/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:55:50 by ismonter          #+#    #+#             */
/*   Updated: 2026/02/27 20:00:37 by ismonter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_flags(int **flags, int num_flags)
{
	if (num_flags == 2)
	{
		if((*flags)[0] < 5 && (*flags)[1] == 5)
			return (1);
		if((*flags)[0] == 5 && (*flags)[1] < 5)
			return (1);
	}
	else
	{
		return (1);
	}
	return (0);
}

int ft_count_flags(int argc, char **argv)
{
	int	i;
	int	num_flags;

	i = 1;
	num_flags = 0;
	while (i < argc)
	{
		if (ft_isflag(argv[i]) != 0)
			num_flags++;
		i++;
	}
	return (num_flags);
}
int	ft_gen_flags(int argc, char **argv, int num_flags, int **flags)
{
	int	i;
	int j;
	
	i = 1;
	j = 0;
	*flags = ft_calloc((num_flags + 1), (sizeof(int)));
	if (!*flags)
		return (0);
	while(i < argc)
	{
		if (ft_isflag(argv[i]) != 0)
		{
			(*flags)[j] = ft_isflag(argv[i]);
			j++;	
		}
		i++;
	}
	(*flags)[j] = 0;
	return (1);
}

int	ft_flags(int argc, char **argv, int *numbers, int **flags)
{
	int num_flags;
	
	num_flags = ft_count_flags(argc, argv);
	if(num_flags > 2)
	{
		write(2, "Error\n", 6);
		free(numbers);
		return (0);
	}
	if (ft_gen_flags(argc, argv, num_flags, flags) == 0)
		{
			free(numbers);
			return (0);
		}
	if ((ft_check_flags(flags, num_flags)) == 0)
	{
		write(2, "Error\n", 6);
		free(numbers);
		free(*flags);
		return (0);
	}
	return (1);
}
