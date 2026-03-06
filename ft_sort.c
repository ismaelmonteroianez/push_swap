/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 12:51:03 by ismonter          #+#    #+#             */
/*   Updated: 2026/03/06 20:23:58 by ismonter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_one_flag(t_list **a, t_list **b, int flags)
{
	if (flags == 1)
		ft_simple(a, b);
	else if (flags == 2)
		ft_medium(a, b);
	else if (flags == 3)
		ft_complex(a, b);
	else if (flags == 4)
		ft_adaptive(a, b);
	else if (flags == 5)
	{
		ft_adaptive(a, b);
		printf("falta la funcion");
	}
}
void	ft_two_flag(t_list **a, t_list **b, int **flags)
{
	if ((*flags)[0] == 5)
	{
		ft_one_flag(a, b, (*flags)[1]);
		printf("bench en primera posicion");
	}
	else
	{
		ft_one_flag(a, b, (*flags)[0]);
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
	return ;
}
