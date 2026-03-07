/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 20:42:53 by ismonter          #+#    #+#             */
/*   Updated: 2026/03/07 16:43:23 by ismonter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (a == NULL || *a == NULL)
		return (0);
	tmp = a[0]->next;
	ft_lstadd_front(b, a[0]);
	a[0] = tmp;
	return (1);
}

void	pa(t_list **a, t_list **b, t_bench *bench_result)
{
	if (ft_push(b, a) != 0)
	{
		write(1, "pa\n", 3);
		bench_result->pa = bench_result->pa + 1;
	}
}

void	pb(t_list **a, t_list **b, t_bench *bench_result)
{
	if (ft_push(a, b) != 0)
	{
		write(1, "pb\n", 3);
		bench_result->pb = bench_result->pb + 1;
	}
}
