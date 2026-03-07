/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 17:58:27 by ismonter          #+#    #+#             */
/*   Updated: 2026/03/07 18:15:45 by ismonter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_simple(t_list **a, t_list **b, t_bench *bench_result)
{
	t_list	*tmp;
	t_list	*smaller;

	bench_result->algorithm = 1;
	if (ft_lstsize(*a) <= 5)
		return (ft_tiny_sort(a, b, ft_lstsize(*a), bench_result));
	while ((*a)->next != NULL)
	{
		smaller = *a;
		tmp = (*a)->next;
		while (tmp != NULL)
		{
			if (smaller->number > tmp->number)
				smaller = tmp;
			tmp = tmp->next;
		}
		while (smaller != *a)
			ra(a, bench_result);
		pb(a, b, bench_result);
	}
	pb(a, b, bench_result);
	while ((*b)->next != NULL)
		pa(a, b, bench_result);
	pa(a, b, bench_result);
	return ;
}
