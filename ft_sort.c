/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarc4 <davgarc4@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 12:51:03 by ismonter          #+#    #+#             */
/*   Updated: 2026/03/02 19:54:11 by davgarc4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	ft_disorder_index(t_list **a)
{
	float	mistakes;
	float	total_pairs;
	int		i;
	int		j;
	int		size;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	size = ft_lstsize(*a);
	while(i < size - 1)
	{
		j = i + 1;
		while(j < size)
		{
			total_pairs++;
			if (ft_lstiter(*a, i) > ft_lstiter(*a, j))
				mistakes++;
			j++;
		}
		i++;
	}
	return (mistakes/total_pairs);
}

void	ft_sort(t_list **a, t_list **b, int	**flags)
{
	float	disorder_index;
	disorder_index = ft_disorder_index(a);
	ft_medium(a, b);
	return ;
}
