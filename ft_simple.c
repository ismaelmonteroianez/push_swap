/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 17:58:27 by ismonter          #+#    #+#             */
/*   Updated: 2026/03/05 20:06:16 by ismonter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_simple(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*smaller;

	while ((*a)->next != NULL)
	{
		if (ft_lstsize(*a) <= 5)
			return (ft_tiny_sort(a, b, ft_lstsize(*a)));
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
	}
	pb(a, b);
	while ((*b)->next != NULL)
		pa(a, b);
	pa(a, b);
	return ;
}
