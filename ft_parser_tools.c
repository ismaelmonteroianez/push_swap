/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 19:26:52 by davgarc4          #+#    #+#             */
/*   Updated: 2026/02/27 19:16:11 by ismonter         ###   ########.fr       */
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
	int	i;

	i = 0;
	while (i < numbers_size - 1)
	{
		if (numbers[i] > numbers[i + 1])
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
		if (ft_isflag(argv[i]) == 0)
		{
			split = ft_split(argv[i], ' ');
			if (!split)
				return (-1);
			if (split[0] == NULL)
				return (free_error_matrix(split), -1);
			j = 0;
			while (split[j++])
				count++;
			free_full_matrix(split);
		}
		i++;
	}
	return (count);
}

int	ft_isflag(char *s)
{
	int result;
	
	result = 0;
	if (ft_strcmp(s, "--simple") == 0)
		result = 1;
	else if (ft_strcmp(s, "--medium") == 0)
		result = 2;
	else if (ft_strcmp(s, "--complex") == 0)
		result = 3;
	else if (ft_strcmp(s, "--adaptive") == 0)
		result = 4;
	else if (ft_strcmp(s, "--bench") == 0)
		result = 5;
	return (result);
}
