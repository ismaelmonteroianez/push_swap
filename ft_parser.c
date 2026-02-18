/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:41:47 by ismonter          #+#    #+#             */
/*   Updated: 2026/02/18 19:49:16 by ismonter         ###   ########.fr       */
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
		{
			write(2, "Error\n", 6);
			return (NULL);
		}
		while(i < argc - 1)
		{
			matrix[i] = ft_strdup(argv[i + 1]);
			i++;
		}
		matrix[i] = NULL;
	}
	return (matrix);
}

int ft_check_nbr(matrix)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	
}

int *ft_parser(int argc, char **argv)
{
    char	**matrix;

	matrix = ft_matrix_gen(argc, argv);
    if (matrix == NULL)
		return (NULL);
	if (ft_check_nbr(matrix) == 1);
	{

	}
	
}
