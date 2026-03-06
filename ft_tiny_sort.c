/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 19:22:12 by ismonter          #+#    #+#             */
/*   Updated: 2026/03/06 19:55:02 by ismonter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_three(t_list **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->number;
	second = (*a)->next->number;
	third = (*a)->next->next->number;

	if (first > second && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
	return ;
}

void	ft_four(t_list **a, t_list **b)
{
	t_list *smaller;
	t_list *tmp;

	smaller = *a;
	tmp = (*a)->next;
	while (tmp != NULL)
	{
		if (smaller->number > tmp->number)
			smaller = tmp;
		tmp = tmp->next;
	}
	while (smaller != *a)
		ra(a);
	pb(a, b);
	ft_three(a);
	pa(a, b);
	return ;
}

void	ft_five(t_list **a, t_list **b)
{
	t_list *smaller;
	t_list *tmp;
	int i;
	
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
			ra(a);
		pb(a, b);
		i++;
	}
	ft_three(a);
	pa(a, b);
	pa(a, b);
	return ;
}

void	ft_tiny_sort(t_list **a,  t_list **b, int size)
{
	if (size == 2)
		sa(a);
	else if (size == 3)
		ft_three(a);
	else if (size == 4)
		ft_four(a, b);
	else if (size == 5)
		ft_five(a, b);
}
