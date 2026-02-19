/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:39:17 by ismonter          #+#    #+#             */
/*   Updated: 2026/02/19 18:03:20 by ismonter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_partial_matrix(char **matrix, int pos)
{
	while (pos > 0)
		free(matrix[--pos]);
	free(matrix);
}

void   free_full_matrix(char **matrix)
{
    int i;

    i = 0;
    while(matrix[i] != NULL)
        i++;
    while (i >= 0)
    {
		free(matrix[i]);
        i--;
    }
	free(matrix);
}
