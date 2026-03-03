/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 19:57:19 by ismonter          #+#    #+#             */
/*   Updated: 2026/03/03 20:16:11 by ismonter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_medium_sort_aux(t_list **a, t_list **b, int aux, int size)
{
    int i;

    i = 0;
    while (i < size)
	{
		if((*a)->index < aux)
			pb(a, b);
		else
			ra(a);
		i++;
	}
    return ;
}

int		ft_sqrt(int size)
{
	int	i;
	i = 1;
	while (i * i <= size)
		i++;
	return (i - 1);
}