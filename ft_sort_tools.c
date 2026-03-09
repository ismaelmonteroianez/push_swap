/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 19:57:19 by ismonter          #+#    #+#             */
/*   Updated: 2026/03/09 19:20:30 by ismonter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lst_pos(t_list **b, t_list *bigger)
{
	t_list	*tmp;
	int		i;

	tmp = *b;
	i = 0;
	while (bigger->number != tmp->number)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	ft_medium_aux(t_list **a, t_list **b, int aux, t_bench *bench_result)
{
	if ((*a)->index < aux)
		pb(a, b, bench_result);
	else
		ra(a, bench_result);
	return ;
}

int	ft_sqrt(int size)
{
	int	i;

	i = 1;
	while (i * i <= size)
		i++;
	return (i - 1);
}
