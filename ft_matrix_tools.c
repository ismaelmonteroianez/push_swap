/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:39:17 by ismonter          #+#    #+#             */
/*   Updated: 2026/02/27 17:38:56 by ismonter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_partial_matrix(char **matrix, int pos)
{
	if (!matrix)
		return ;
	while (pos > 0)
		free(matrix[--pos]);
	free(matrix);
}

void	free_full_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i] != NULL)
		i++;
	while (i >= 0)
	{
		free(matrix[i]);
		i--;
	}
	free(matrix);
}

int	free_error_matrix(char **matrix)
{
	free_full_matrix(matrix);
	write(2, "Error\n", 6);
	return (0);
}

int	matrix_len(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
		i++;
	return (i);
}

char	**fill_matrix(int argc, char **argv, char **matrix, int i)
{
	int		j;
	int		k;
	char	**split;

	k = 0;
	while (++i < argc)
	{
		if (ft_check_flags(argv[i]) == 0)
		{
			split = ft_split(argv[i], ' ');
			if (!split)
				return (free_full_matrix(matrix), NULL);
			j = 0;
			while (split[j])
			{
				matrix[k++] = ft_strdup(split[j++]);
				if (matrix[k - 1] == NULL)
					return (free_full_matrix(split),
						free_full_matrix(matrix), NULL);
			}
			free_full_matrix(split);
		}
	}
	matrix[k] = NULL;
	return (matrix);
}
