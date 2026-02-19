/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:41:47 by ismonter          #+#    #+#             */
/*   Updated: 2026/02/19 18:28:47 by ismonter         ###   ########.fr       */
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
	j = 0;
	while(matrix[i] != NULL)
	{
		while(matrix[i][j] != '\0')
		{
			if(matrix[i][j] == '-')
			if (ft_isdigit(matrix[i][j]) == 0)
				{
					free_full_matrix(matrix);
					write(2, "Error\n", 6);
					return (0);
				}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int *ft_parser(int argc, char **argv)
{
    char	**matrix;
	int		check;

	matrix = ft_matrix_gen(argc, argv);
    if (matrix == NULL)
		return (NULL);
	check = ft_check_nbr(matrix);
	if(check == 0)
		return (NULL);
	
	
	
}



if (str[0] == '-' && 

-5---