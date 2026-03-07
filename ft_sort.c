/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarc4 <davgarc4@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 12:51:03 by ismonter          #+#    #+#             */
/*   Updated: 2026/03/07 13:29:08 by davgarc4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_one_flag(t_list **a, t_list **b, int flags)
{
	if (flags == 1)
		ft_simple(a, b);
	else if (flags == 2)
	{
		if (ft_medium(a, b) == 0)
			return (0);
	}
	else if (flags == 3)
	{
		if (ft_complex(a, b) == 0)
			return (0);
	}
	else if (flags == 4)
	{
		if (ft_adaptive(a, b) == 0)
			return (0);
	}
	else if (flags == 5)
	{
		if (ft_adaptive(a, b) == 0)
			return (0);
		printf("falta la funcion");
	}
	return (1);
}
void	ft_two_flag(t_list **a, t_list **b, int **flags)
{
	if ((*flags)[0] == 5)
	{
		if (ft_one_flag(a, b, (*flags)[1]) == 0)
			return ;
		printf("bench en primera posicion");
	}
	else
	{
		if (ft_one_flag(a, b, (*flags)[0]) == 0)
			return ;
		printf("bench en segunda posicion");
	}
}


void	ft_sort(t_list **a, t_list **b, int	**flags)
{

	int		num_flags;
	
	num_flags = 0;
	while ((*flags)[num_flags] != 0)
		num_flags++;
	if (num_flags == 0)
		ft_adaptive(a, b);
	else if (num_flags == 1)
		ft_one_flag(a, b, (*flags)[0]);
	else if (num_flags == 2)
		ft_two_flag(a, b, flags);
	ft_lstclear(a);
	free(*flags);
	return ;
}
