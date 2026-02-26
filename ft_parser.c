/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:41:47 by ismonter          #+#    #+#             */
/*   Updated: 2026/02/26 18:34:09 by ismonter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_matrix_gen(int argc, char **argv)
{
	char	**matrix;
	int		total;

	if (argc < 2)
		return (NULL);
	total = count_total_numbers(argc, argv);
	if (total <= 0)
		return (NULL);
	matrix = ft_calloc(total + 1, sizeof(char *));
	if (!matrix)
		return (NULL);
	matrix = fill_matrix(argc, argv, matrix);
	if (!matrix)
		return (NULL);
	return (matrix);
}

int	ft_check_nbr(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i] != NULL)
	{
		j = 0;
		if (matrix[i][j] == '-')
		{
			j++;
			if (matrix[i][j] == '\0')
				return (free_error_matrix(matrix));
		}
		while (matrix[i][j] != '\0')
		{
			if (ft_isdigit(matrix[i][j]) == 0)
				return (free_error_matrix(matrix));
			j++;
		}
		i++;
	}
	return (1);
}

int	*ft_array_number_gen(char **matrix)
{
	long	result_atol;
	int		*numbers;
	int		i;

	i = 0;
	numbers = ft_calloc(matrix_len(matrix), sizeof(int));
	if (numbers == NULL)
	{
		free_full_matrix(matrix);
		return (NULL);
	}
	while (matrix[i] != NULL)
	{
		result_atol = ft_atol(matrix[i]);
		if (ft_check_int(result_atol) == 0)
		{
			free_error_matrix(matrix);
			free(numbers);
			return (NULL);
		}
		numbers[i] = (int)result_atol;
		i++;
	}
	free_full_matrix(matrix);
	return (numbers);
}

int	check_repeated_numbers(int *numbers, int numbers_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < numbers_size - 1)
	{
		j = i + 1;
		while (j < numbers_size)
		{
			if (numbers[i] == numbers[j])
			{
				free(numbers);
				write(2, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	*ft_parser(int argc, char **argv, int *numbers_size)
{
	char	**matrix;
	int		check;
	int		*numbers;

	matrix = ft_matrix_gen(argc, argv);
	if (matrix == NULL)
		return (NULL);
	check = ft_check_nbr(matrix);
	if (check == 0)
		return (NULL);
	*numbers_size = matrix_len(matrix);
	numbers = ft_array_number_gen(matrix);
	if (numbers == NULL)
		return (NULL);
	if (check_repeated_numbers(numbers, *numbers_size) == 0)
		return (NULL);
	if (ft_check_order(numbers, *numbers_size) == 1)
	{
		free(numbers);
		return (NULL);
	}
	return (numbers);
}
