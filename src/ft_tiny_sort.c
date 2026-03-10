/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 19:22:12 by ismonter          #+#    #+#             */
/*   Updated: 2026/03/10 19:10:34 by ismonter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_three(t_list **a, t_bench *bench_result)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->number;
	second = (*a)->next->number;
	third = (*a)->next->next->number;
	if (first > second && first < third)
		sa(a, bench_result);
	else if (first > second && second > third)
	{
		sa(a, bench_result);
		rra(a, bench_result);
	}
	else if (first > second && second < third && first > third)
		ra(a, bench_result);
	else if (second > third && first < third)
	{
		sa(a, bench_result);
		ra(a, bench_result);
	}
	else if (first < second && second > third && first > third)
		rra(a, bench_result);
	return ;
}

void	ft_four(t_list **a, t_list **b, t_bench *bench_result)
{
	t_list	*smaller;
	t_list	*tmp;

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
	ft_three(a, bench_result);
	pa(a, b, bench_result);
	return ;
}

void	ft_five(t_list **a, t_list **b, t_bench *bench_result)
{
	t_list	*smaller;
	t_list	*tmp;
	int		i;

	i = 0;
	while (i < 2)
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
		i++;
	}
	ft_three(a, bench_result);
	pa(a, b, bench_result);
	pa(a, b, bench_result);
	return ;
}

void	ft_tiny_sort(t_list **a, t_list **b, int size, t_bench *bench_result)
{
	if (size == 2)
		sa(a, bench_result);
	else if (size == 3)
		ft_three(a, bench_result);
	else if (size == 4)
		ft_four(a, b, bench_result);
	else if (size == 5)
		ft_five(a, b, bench_result);
}
