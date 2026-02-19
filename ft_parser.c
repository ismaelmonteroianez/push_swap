/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarc4 <davgarc4@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:41:47 by ismonter          #+#    #+#             */
/*   Updated: 2026/02/19 20:08:08 by davgarc4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_matrix_gen(int argc, char **argv)
{
	int		i;
	char	**matrix;

    i = 0;
    if (argc == 1)
		return (NULL);
	if (argc == 2)
		matrix = ft_split(argv[1], ' ');
	if (argc > 2)
    {
        matrix = ft_calloc(argc, sizeof(char *));
		if (matrix == NULL)
			return (NULL);
		while(i < argc - 1)
		{
			matrix[i] = ft_strdup(argv[i + 1]);
			if (matrix[i] == NULL)
					return (free_partial_matrix(matrix, i), NULL);
			i++;
		}
		matrix[i] = NULL;
	}
	return (matrix);
}

int ft_check_nbr(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	while(matrix[i] != NULL)
	{
		j = 0;
		if (matrix[i][j] == '-')
		{
			j++;
			if(matrix[i][j] == '\0')
				return (free_error_matrix(matrix));
		}
		while(matrix[i][j] != '\0')
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
	return(numbers);
}


int *ft_parser(int argc, char **argv)
{
    char	**matrix;
	int		check;
	int		*numbers;
	int		numbers_size;
	
	matrix = ft_matrix_gen(argc, argv);
    if (matrix == NULL)
		return (NULL);
	check = ft_check_nbr(matrix);
	if(check == 0)
		return (NULL);
	numbers_size = matrix_len(matrix);
	numbers = ft_array_number_gen(matrix);
	if (numbers == NULL)
		return (NULL);

	int i;
	i = 0;
	while (i < numbers_size)
	{
		printf("%d\n", numbers[i]);
		i++;
	}
	return (NULL);
}
