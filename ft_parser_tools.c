/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 19:26:52 by davgarc4          #+#    #+#             */
/*   Updated: 2026/02/25 20:27:02 by ismonter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_int(long n)
{
	if (n > INT_MAX || n < INT_MIN)
	{
		return (0);
	}
	else
		return (1);
}
int	ft_check_order(int *numbers, int numbers_size)
{
	int i;

	i = 0;
	while(i < numbers_size - 1)
	{
		if(numbers[i] > numbers[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	count_total_numbers(int argc, char **argv)
{
	int		i;
	int		j;
	int		count;
	char	**split;

	count = 0;
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (-1);
		if (split[0] == NULL)
			return (write(1, "Error\n", 6), -1);
		j = 0;
		while (split[j])
		{
			count++;
			j++;
		}
		free_full_matrix(split);
		i++;
	}
	return (count);
}
