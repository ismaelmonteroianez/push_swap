/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adaptive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarc4 <davgarc4@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 18:11:53 by ismonter          #+#    #+#             */
/*   Updated: 2026/03/07 13:22:50 by davgarc4         ###   ########.fr       */
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
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			total_pairs++;
			if (ft_lstiter(*a, i) > ft_lstiter(*a, j))
				mistakes++;
			j++;
		}
		i++;
	}
	return (mistakes / total_pairs);
}

int	ft_adaptive(t_list **a, t_list **b)
{
	float	disorder_index;

	disorder_index = ft_disorder_index(a);
	if (disorder_index < 0.2)
		ft_simple(a, b);
	else if (disorder_index < 0.5)
	{	
		if (ft_medium(a, b) == 0)
			return (0);
	}	
	else
		if (ft_complex(a, b) == 0)
			return (0);
	return (1);
}	
